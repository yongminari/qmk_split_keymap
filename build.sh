#!/usr/bin/env bash
#
# QMK Compile helper script for Corne v4.1
#

# 스크립트 실행 중 에러 발생 시 즉시 중단
set -euo pipefail

SCRIPT_DIR="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" && pwd)"
QMK_FIRMWARE_DIR="${QMK_FIRMWARE_DIR:-/home/yongminari/qmk_firmware}"
FW_PATH="$SCRIPT_DIR/crkbd_rev4_1_standard_yongminari.uf2"

# Keep the keymap outside qmk_firmware using QMK's External Userspace support.
export QMK_USERSPACE="$SCRIPT_DIR"

case "${1:-}" in
    --update)
        "$SCRIPT_DIR/update_qmk.sh"
        ;;
    --help|-h)
        echo "사용법: $0 [--update]"
        echo "  --update  공식 QMK의 최신 안정 태그로 이동한 뒤 빌드"
        exit 0
        ;;
    "")
        ;;
    *)
        echo "오류: 알 수 없는 옵션: $1"
        echo "사용법: $0 [--update]"
        exit 1
        ;;
esac

if ! git -C "$QMK_FIRMWARE_DIR" rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    echo "오류: QMK 저장소를 찾을 수 없습니다: $QMK_FIRMWARE_DIR"
    exit 1
fi

QMK_VERSION="$(git -C "$QMK_FIRMWARE_DIR" describe --tags --exact-match HEAD 2>/dev/null \
    || git -C "$QMK_FIRMWARE_DIR" rev-parse --short HEAD)"

echo "==> [1/2] QMK $QMK_VERSION 펌웨어 컴파일을 시작합니다..."
cd "$QMK_FIRMWARE_DIR"
qmk compile -kb crkbd/rev4_1/standard -km yongminari --clean

# 빌드 결과물 UF2 파일 확인
if [ -f "$FW_PATH" ]; then
    echo "==> [2/2] [성공] 펌웨어 컴파일이 성공적으로 완료되었습니다!"
    echo "==> 빌드된 파일 위치: $FW_PATH"
else
    echo "오류: 컴파일은 정상 종료되었으나 UF2 파일($FW_PATH)을 찾을 수 없습니다."
    exit 1
fi
