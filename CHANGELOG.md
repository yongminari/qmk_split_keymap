# Changelog

이 프로젝트는 [Semantic Versioning](https://semver.org/)을 따릅니다.

## 0.2.0 - 2026-09-04

- 내부 추가 키 4개를 모든 레이어에서 비활성화하여 완전한 3x5+3 구성으로 정리
- Function 레이어 진입 키를 `V`와 `M` 위치로 이동
- Num 레이어의 백틱, 작은따옴표, 중괄호 위치와 Navi 레이어의 Enter 위치 조정
- `flash.sh`에 장치 이름 검증 및 자동 마운트 방식의 UF2 플래싱 지원 추가

## 0.1.0 - 2026-08-14

- Corne v4.1용 3x5+3 커스텀 키맵의 첫 버전 릴리스
- `_DEFAULT`, `_NAV`, `_NUM`, `_FUNC` 레이어 구성
- Home Row Mods, Caps Word, RGB Matrix 및 마우스 키 지원
- GitHub Actions 기반 QMK 빌드와 버전 릴리스 자동화
