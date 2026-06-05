#!/usr/bin/env bash
#
# QMK Flash helper script for Corne v4.1 (Without compilation)
#

# 스크립트 실행 중 에러 발생 시 즉시 중단
set -e

# 인자 확인
if [ -z "$1" ]; then
    echo "오류: 디바이스 이름을 입력해주세요."
    echo "사용법: $0 <device_name> (예: sdb1 또는 /dev/sdb1)"
    echo "사용 가능한 USB 드라이브를 확인하려면 'lsblk'를 이용해 RPI-RP2 볼륨의 장치명을 확인하세요."
    exit 1
fi

DEVICE="$1"

# /dev/ 접두사가 없는 경우 자동으로 붙여줌
if [[ "$DEVICE" != /dev/* ]]; then
    DEVICE="/dev/$DEVICE"
fi

# 블록 장치 존재 여부 확인
if [ ! -b "$DEVICE" ]; then
    echo "오류: 장치 '$DEVICE'를 찾을 수 없거나 유효한 블록 장치가 아닙니다."
    echo "'lsblk' 명령어로 현재 마운트된 부트로더(RPI-RP2) 장치명을 확인해주세요."
    exit 1
fi

FW_PATH="/home/yongminari/qmk_firmware/crkbd_rev4_1_standard_yongminari.uf2"

# 빌드 결과물 UF2 파일 확인
if [ ! -f "$FW_PATH" ]; then
    echo "오류: UF2 파일($FW_PATH)을 찾을 수 없습니다."
    echo "먼저 './build.sh'를 실행하여 펌웨어를 빌드해주세요."
    exit 1
fi

echo "==> 펌웨어 파일($FW_PATH)을 장치($DEVICE)에 플래싱합니다..."
echo "dd 명령 실행을 위해 sudo 권한(비밀번호)이 필요할 수 있습니다."
sudo dd if="$FW_PATH" of="$DEVICE" conv=fdatasync status=progress

echo "==> [완료] 플래싱이 성공적으로 완료되었습니다!"
