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

if [ -n "${1:-}" ]; then
    MOUNT_POINT="$1"
elif command -v findmnt >/dev/null 2>&1; then
    MOUNT_POINT="$(findmnt -rnf -S LABEL=RPI-RP2 -o TARGET)"
else
    MOUNT_POINT=""
fi

if [ -z "$MOUNT_POINT" ]; then
    echo "오류: 마운트된 RPI-RP2 볼륨을 찾지 못했습니다."
    echo "키보드를 부트로더 모드로 연결한 뒤 다시 실행하거나 마운트 경로를 지정해주세요."
    echo "사용법: $0 [/path/to/RPI-RP2]"
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
