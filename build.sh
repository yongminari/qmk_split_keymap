#!/usr/bin/env bash
#
# QMK Compile helper script for Corne v4.1
#

# 스크립트 실행 중 에러 발생 시 즉시 중단
set -e

FW_PATH="/home/yongminari/qmk_firmware/crkbd_rev4_1_standard_yongminari.uf2"

echo "==> [1/2] QMK 펌웨어 컴파일을 시작합니다..."
cd ~/qmk_firmware
qmk compile -kb crkbd/rev4_1/standard -km yongminari --clean

# 빌드 결과물 UF2 파일 확인
if [ -f "$FW_PATH" ]; then
    echo "==> [2/2] [성공] 펌웨어 컴파일이 성공적으로 완료되었습니다!"
    echo "==> 빌드된 파일 위치: $FW_PATH"
else
    echo "오류: 컴파일은 정상 종료되었으나 UF2 파일($FW_PATH)을 찾을 수 없습니다."
    exit 1
fi
