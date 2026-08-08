#!/usr/bin/env bash
#
# Move the local QMK checkout to the latest stable release tag.
#

set -euo pipefail

QMK_FIRMWARE_DIR="${QMK_FIRMWARE_DIR:-/home/yongminari/qmk_firmware}"
QMK_REMOTE="${QMK_REMOTE:-origin}"

if ! git -C "$QMK_FIRMWARE_DIR" rev-parse --is-inside-work-tree >/dev/null 2>&1; then
    echo "오류: QMK 저장소를 찾을 수 없습니다: $QMK_FIRMWARE_DIR"
    echo "다른 위치를 사용한다면 QMK_FIRMWARE_DIR 환경 변수를 지정해주세요."
    exit 1
fi

# Untracked files (including the custom keymap symlink) are intentionally allowed,
# but never switch versions over modifications to tracked QMK files.
if ! git -C "$QMK_FIRMWARE_DIR" diff --quiet || \
   ! git -C "$QMK_FIRMWARE_DIR" diff --cached --quiet; then
    echo "오류: QMK 저장소의 추적 파일에 커밋되지 않은 변경이 있습니다."
    echo "변경을 커밋하거나 임시 보관한 뒤 다시 실행해주세요."
    git -C "$QMK_FIRMWARE_DIR" status --short
    exit 1
fi

echo "==> 공식 QMK 저장소에서 최신 안정 태그를 확인합니다..."
LATEST_TAG="$({
    git -C "$QMK_FIRMWARE_DIR" ls-remote --tags --refs "$QMK_REMOTE" 'refs/tags/[0-9]*' \
        | awk '$2 ~ /^refs\/tags\/[0-9]+\.[0-9]+\.[0-9]+$/ { sub("refs/tags/", "", $2); print $2 }' \
        | sort -V \
        | tail -n 1
})"

if [[ -z "$LATEST_TAG" ]]; then
    echo "오류: 최신 QMK 안정 태그를 확인하지 못했습니다. 네트워크와 remote 설정을 확인해주세요."
    exit 1
fi

CURRENT_VERSION="$(git -C "$QMK_FIRMWARE_DIR" describe --tags --exact-match HEAD 2>/dev/null \
    || git -C "$QMK_FIRMWARE_DIR" rev-parse --short HEAD)"

echo "==> 현재 QMK: $CURRENT_VERSION"
echo "==> 최신 안정 QMK: $LATEST_TAG"

if [[ "$CURRENT_VERSION" != "$LATEST_TAG" ]]; then
    git -C "$QMK_FIRMWARE_DIR" fetch --no-tags "$QMK_REMOTE" \
        "refs/tags/$LATEST_TAG:refs/tags/$LATEST_TAG"
    git -C "$QMK_FIRMWARE_DIR" switch --detach "$LATEST_TAG"
else
    echo "==> 이미 최신 안정 태그를 사용 중입니다."
fi

echo "==> QMK 서브모듈을 동기화합니다..."
git -C "$QMK_FIRMWARE_DIR" submodule sync --recursive
git -C "$QMK_FIRMWARE_DIR" submodule update --init --recursive

echo "==> QMK $LATEST_TAG 준비가 완료되었습니다."
