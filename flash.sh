#!/usr/bin/env bash
#
# QMK UF2 flash helper for Corne v4.1
#

set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
FW_PATH="$SCRIPT_DIR/crkbd_rev4_1_standard_yongminari.uf2"

if [ ! -f "$FW_PATH" ]; then
    echo "오류: UF2 파일($FW_PATH)을 찾을 수 없습니다."
    echo "릴리스 압축 파일을 다시 풀거나 './build.sh'로 먼저 빌드해주세요."
    exit 1
fi

MOUNT_POINT=""

if [ -n "${1:-}" ]; then
    TARGET="$1"
    DEVICE=""

    if [[ "$TARGET" == /dev/* ]]; then
        DEVICE="$TARGET"
    elif [ -b "/dev/$TARGET" ]; then
        DEVICE="/dev/$TARGET"
    elif [ -d "$TARGET" ]; then
        MOUNT_POINT="$TARGET"
    else
        echo "오류: '$TARGET'에 해당하는 블록 장치나 마운트 경로를 찾을 수 없습니다."
        echo "사용법: $0 [sdc1|/dev/sdc1|/path/to/RPI-RP2]"
        exit 1
    fi

    if [ -n "$DEVICE" ]; then
        if [ ! -b "$DEVICE" ]; then
            echo "오류: '$DEVICE'는 블록 장치가 아닙니다."
            exit 1
        fi
        if ! command -v lsblk >/dev/null 2>&1; then
            echo "오류: 장치 정보를 확인하는 데 필요한 lsblk를 찾을 수 없습니다."
            exit 1
        fi

        VOLUME_LABEL="$(lsblk -dnro LABEL -- "$DEVICE")"
        if [ "$VOLUME_LABEL" != "RPI-RP2" ]; then
            echo "오류: '$DEVICE'의 볼륨 라벨은 '${VOLUME_LABEL:-없음}'입니다."
            echo "안전을 위해 RPI-RP2 볼륨에만 플래싱할 수 있습니다."
            exit 1
        fi

        MOUNT_POINT="$(lsblk -dnro MOUNTPOINT -- "$DEVICE")"

        if [ -z "$MOUNT_POINT" ]; then
            if ! command -v udisksctl >/dev/null 2>&1; then
                echo "오류: '$DEVICE'가 마운트되지 않았고 udisksctl도 찾을 수 없습니다."
                echo "장치를 직접 마운트한 뒤 마운트 경로를 지정해주세요."
                exit 1
            fi

            echo "==> $DEVICE 를 마운트합니다..."
            udisksctl mount -b "$DEVICE"
            MOUNT_POINT="$(lsblk -dnro MOUNTPOINT -- "$DEVICE")"
        fi

        if [ -z "$MOUNT_POINT" ]; then
            echo "오류: '$DEVICE'의 마운트 경로를 확인할 수 없습니다."
            exit 1
        fi
    fi
elif command -v findmnt >/dev/null 2>&1; then
    MOUNT_POINT="$(findmnt -rnf -S LABEL=RPI-RP2 -o TARGET || true)"
fi

if [ -z "$MOUNT_POINT" ]; then
    echo "오류: 마운트된 RPI-RP2 볼륨을 찾지 못했습니다."
    echo "키보드를 부트로더 모드로 연결한 뒤 다시 실행하거나 마운트 경로를 지정해주세요."
    echo "사용법: $0 [sdc1|/dev/sdc1|/path/to/RPI-RP2]"
    exit 1
fi

if [ ! -d "$MOUNT_POINT" ] || [ ! -f "$MOUNT_POINT/INFO_UF2.TXT" ]; then
    echo "오류: '$MOUNT_POINT'는 RP2040 UF2 부트로더 볼륨이 아닙니다."
    echo "RPI-RP2 볼륨 안의 INFO_UF2.TXT를 확인해주세요."
    exit 1
fi

echo "==> $MOUNT_POINT 에 펌웨어를 복사합니다..."
cp "$FW_PATH" "$MOUNT_POINT/"
sync

echo "==> [완료] 플래싱이 성공적으로 완료되었습니다!"
echo "==> RPI-RP2 볼륨이 자동으로 연결 해제되는 것은 정상입니다."
