# Changelog

이 프로젝트는 [Semantic Versioning](https://semver.org/)을 따릅니다.

## 0.4.1 - 2026-09-06

- `T/Y` 홀드의 Shift가 다음 NAV 키 입력 시 초기화되던 weak modifier 처리를 일반 modifier로 교체
- `T/Y` 탭은 기존 문자를 유지하고, 홀드 시 Navigation+Shift가 방향키 입력까지 정상 유지되도록 수정

## 0.4.0 - 2026-09-06

- `T/Y`를 탭하면 기존 문자, 홀드하면 Navigation+Shift로 동작하도록 좌우 대칭 배치
- Num 레이어의 중복 `=`과 `?` 자리를 틸드(`~`)와 큰따옴표(`"`)로 바꿔 Shift 없이 직접 입력할 수 있게 조정
- Function 레이어 왼쪽의 중복 `F1`~`F12`를 제거하고 `KC_NO`로 완전히 비활성화
- 레이어 조합 사용 시 `엄지 + 엄지 + 다른 키`를 요구하는 3키 조합을 최대한 피하도록 키맵 정리

## 0.3.1 - 2026-09-04

- CI 및 릴리스 빌드가 실행 시점의 최신 QMK 안정 태그를 자동으로 사용하도록 변경
- 릴리스에 실제 사용한 QMK 버전을 `QMK_VERSION.txt`로 기록

## 0.3.0 - 2026-09-04

- `W/O`, `E/I`, `R/U`에 각각 GUI+Shift, Alt+Shift, Ctrl+Shift 홀드를 좌우 대칭으로 추가
- 탭 시 기존 문자를 유지하는 Shift Combo Mods 배치와 사용법을 README에 반영

## 0.2.1 - 2026-09-04

- `V_FUNC`와 `M_FUNC`의 탭/홀드 시간을 Home Row Mods와 동일한 200ms로 조정
- Chordal Hold와 Flow Tap을 제거하여 다른 키 입력과 무관하게 누른 시간만으로 판정하고 연속 탭 문자 반복은 유지

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
