# ⌨️ Corne v4.1 (46-key) QMK Custom Configuration

이 프로젝트는 **Corne v4.1 (RP2040)** 분할 키보드를 위한 커스텀 QMK 펌웨어 설정 저장소입니다. 기존 NixOS Kanata 설정을 바탕으로 Home Row Mods 및 다중 레이어를 구현했습니다.

## 🛠 Hardware Info
- **Model:** Corne v4.1 (Standard, 46-key version)
- **MCU:** RP2040 (Integrated)
- **Layout:** 3x6_3 with 2 extra inner keys per side (`LAYOUT_split_3x6_3_ex2`)

## ⌨️ Visual Layout

### 1. Default Layer (`_DEFAULT`)
기본 타이핑 레이어입니다. 홀드 시 모디파이어(GACS) 또는 레이어 전환으로 동작합니다. 콤마(`,`)와 `V` 키의 레이어 모디파이어 기능을 빼서 일반 키로 환원하여 타이핑 반응 속도를 최적화했습니다.

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
ESC   Q     W     E     R     T    ENT | DEL   Y     U     I     O     P     BSPC
LCTL  A(G)  S(A)  D(C)  F(S)  G(Sym)TAB | TG(R) H     J(S)  K(C)  L(A)  ;(G)  '
LSFT  Z(F)  X     C     V     B        | N(Nav)M     ,     .     /     RSFT
            Num   Nav   TAB            | ENT   SPC(E)RALT(Sym)
```
*(G=GUI, A=Alt, C=Ctrl, S=Shift, TG(R)=RAW Toggle, Num=Number Layer, Nav=Navigation Layer, Z(F)=Z hold for Func Layer, SPC(E)=Extra Layer, RALT(Sym)=RALT hold for Symbols, TAB=Tab)*

### 2. Navigation Layer (`_NAV`)
방향키와 마우스 제어 레이어입니다. (**왼쪽 엄지 중간** 키 `Nav` 홀드 또는 `N` 키 홀드 시 진입)

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
-     ACL0  WH_L  WH_D  WH_U  WH_R  -  | -     HOME  PGUP  PGDN  END   -     -
-     ACL2  MS_L  MS_D  MS_U  MS_R  -  | -     LEFT  DOWN  UP    RGHT  -     -
-     -     BTN1  BTN3  BTN2  -        | -     BSPC  DEL   -     -     -
            -     -     -              | -     -     -
```
*(ACL0/2=마우스 가속 속도 0/2, WH_L/D/U/R=마우스 휠 좌/하/상/우, MS_L/D/U/R=마우스 커서 이동 좌/하/상/우, BTN1/3/2=마우스 좌클릭/휠클릭/우클릭, BSPC=Backspace, DEL=Delete)*

### 3. Number Pad (`_NUM`)
숫자 입력 레이어입니다. (**왼쪽 엄지 바깥쪽** 키 홀드 시 진입)

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
-     -     -     -     -     -     -  | -     /     7     8     9     -     -
-     -     -     -     -     -     -  | -     *     4     5     6     +     -
-     -     -     -     -     -        | -     1     2     3     .     -
            -     -     -              | -     0     -
```
*(0 키는 우측 엄지 중간에 매핑되어 숫자 키패드를 한 손으로 다루기 편리하도록 구성되었습니다.)*

### 4. Symbols (`_SYM`)
특수 기호 레이어입니다. (`G` 키 홀드 또는 **오른쪽 엄지 바깥쪽 RALT(Sym)** 키 홀드 시 진입)

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
-     !     @     #     $     %     -  | -     [     ]     {     }     `     -
-     ^     &     *     -     =     -  | -     (     )     '     "     :     -
-     ~     _     +     |     \        | -     -     -     -     -     -
            -     -     -              | -     -     -
```

### 5. Function Layer (`_FUNC`)
키보드 F1 ~ F12 펑션키 입력 레이어입니다. (**`Z` 키 홀드** 시 진입)

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
-     -     -     -     -     -     -  | -     F12   F7    F8    F9    -     -
-     -     -     -     -     -     -  | -     F11   F4    F5    F6    -     -
-     -     -     -     -     -        | F10   F1    F2    F3    -     -
            -     -     -              | -     -     -
```

### 6. Extra Layer (`_EXTRA`)
RGB Matrix 제어 및 특수 키 입력 레이어입니다. (**오른쪽 엄지 중간 Space 키** 홀드 시 진입)

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
-     TAB   -     -     -     -     -  | -     TOGG  NEXT  -     -     -     -
-     -     -     -     -     -     -  | -     HUE+  SAT+  VAL+  -     -     -
-     -     -     -     -     -        | HUE-  SAT-  VAL-  -     -     -
            -     -     -              | -     -     -
```
*(TAB=Q 위치에서 Tab 입력, TOGG=RGB Matrix On/Off, NEXT=RGB Matrix 모드 전환, HUE+/HUE-=색상 증가/감소, SAT+/SAT-=채도 증가/감소, VAL+/VAL-=밝기 증가/감소)*

### 7. RAW Layer (`_RAW`)
홈로우 모드가 일시 정지된 일반 키보드 레이어입니다. 게임 실행이나 빠른 연속 타이핑 등 단일 키 입력 처리가 요구될 때 유용합니다. (`TG(_RAW)` 키로 토글하여 활성화/비활성화)

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
ESC   Q     W     E     R     T    ENT | DEL   Y     U     I     O     P     BSPC
LCTL  A     S     D     F     G    TAB | TG(R) H     J     K     L     ;     '
LSFT  Z     X     C     V     B        | N     M     ,     .     /     RSFT
            LALT  LGUI  TAB            | ENT   SPC   RALT
```

---

## 🚀 Quick Start (NixOS)

### 1. 동기화 (최초 1회 실행)
저장소의 설정을 `qmk_firmware` 폴더 내의 Corne 키맵 위치로 심볼릭 링크를 설정합니다.

```bash
# 기존 디렉토리가 존재한다면 삭제 (또는 백업)
rm -rf ~/qmk_firmware/keyboards/crkbd/keymaps/yongminari

# 올바른 경로로 심볼릭 링크 설정
ln -s /home/yongminari/Workspace/sources/repos/qmk_custom/keymaps/yongminari ~/qmk_firmware/keyboards/crkbd/keymaps/yongminari
```

### 2. Build (펌웨어 컴파일)
저장소 루트의 빌드 헬퍼 스크립트를 사용하여 펌웨어를 빌드합니다.

```bash
./build.sh
```

### 3. Flash (펌웨어 다운로드)
스플릿 키보드의 부트로더 모드(RPI-RP2)에 각각 연결한 뒤 플래시 헬퍼 스크립트를 사용하여 양쪽에 펌웨어를 다운로드합니다.
- **부트로더 진입 방법:**
  - **왼쪽:** `Q` 키를 누른 채 USB 연결
  - **오른쪽:** `P` 키를 누른 채 USB 연결

```bash
# 장치 이름(sdX1 등)은 lsblk 명령어로 확인 필수
./flash.sh sdX1
```
*(스플릿 키보드 특성상 양쪽 각각 한 번씩 총 2번 이 명령어로 플래싱을 수행해줍니다.)*

---

## ⌨️ Keymap Features
- **Home Row Mods (GACS):** `A,S,D,F / J,K,L,;` 키에 GUI, Alt, Ctrl, Shift 적용.
- **Tapping Term:** 180ms 일괄 적용.
- **Tapping Optimizations:** 오작동 방지를 위해 `HOLD_ON_OTHER_KEY_PRESS` 및 `PERMISSIVE_HOLD` 제거.
- **Layers:**
  - `_DEFAULT`: 기본 알파 및 Home Row Mods.
  - `_NAV`: 방향키, 마우스 제어. **왼쪽 엄지 중간 키**(`MO(_NAV)`) 또는 `N` 키 홀드로 진입.
  - `_NUM`: Kanata 스타일 숫자 패드. **왼쪽 엄지 바깥쪽** 키(`MO(_NUM)`)로 진입.
  - `_SYM`: Kanata 스타일 특수 기호. `G` 키 홀드 또는 **오른쪽 엄지 바깥쪽 키**(`LT(_SYM, KC_RALT)`) 홀드로 진입.
  - `_FUNC`: F1 ~ F12 기능 키 입력. **`Z` 키 홀드**(`LT(_FUNC, KC_Z)`)로 진입.
  - `_EXTRA`: **Space 홀드 시 활성화. `Space + Q` 조합으로 `Tab` 입력 및 RGB Matrix 효과 제어.**
  - `_RAW`: 홈로우 정지 모드 (오른쪽 검지 안쪽 키로 토글).
- **Key Position Changes for Optimization (타이핑 딜레이 최소화):**
  - **`V` 및 `,` (쉼표) 키**: 레이어 모디파이어 기능을 완전히 분리하여 일반 키로 지정, 타이핑 시 오작동과 딜레이 원천 방지.
  - **`Z` 키**: `LT(_FUNC, KC_Z)`로 설정하여 펑션(`_FUNC`) 레이어 진입 키로 사용.
  - **오른쪽 엄지 바깥쪽 (`RALT`)**: `LT(_SYM, KC_RALT)`로 설정하여 탭 시 한영 전환, 홀드 시 `_SYM` 레이어 진입으로 효율성 극대화.
  - **왼쪽 엄지 중간**: `MO(_NAV)`로 설정하여 방향키/마우스 레이어로 직관적 진입.
  - **왼쪽 엄지 안쪽**: 당분간 `KC_TAB` 키 유지.

## 📌 TODO
- [ ] 레이어별 키 배치 최적화 (사용하면서 보정 필요)
- [ ] 매크로 추가 (한영 전환 등)
- [ ] RGB Matrix 효과 커스텀

## 💡 Notes
- 분할 키보드 통신을 위해 `MASTER_LEFT`가 설정되어 있으므로, 반드시 **왼쪽 키보드**를 컴퓨터에 USB로 연결하여 사용하십시오.
- TRRS 케이블 연결 시 반드시 전원을 끄고 연결하십시오.
