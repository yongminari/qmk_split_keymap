# ⌨️ Corne v4.1 (46-key) QMK Custom Configuration

이 프로젝트는 **Corne v4.1 (RP2040)** 분할 키보드를 위한 커스텀 QMK 펌웨어 설정 저장소입니다. 기존 NixOS Kanata 설정을 바탕으로 Home Row Mods 및 다중 레이어를 구현했습니다.

## 🛠 Hardware Info
- **Model:** Corne v4.1 (Standard, 46-key version)
- **MCU:** RP2040 (Integrated)
- **Layout:** 3x6_3 with 2 extra inner keys per side (`LAYOUT_split_3x6_3_ex2`)

## ⌨️ Visual Layout

### 1. Default Layer (`_DEFAULT`)
기본 타이핑 레이어입니다. 분홍색 키는 홀드 시 모디파이어(GACS) 또는 레이어 전환으로 동작합니다.

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
ESC   Q     W     E     R     T    ENT | DEL   Y     U     I     O     P     BSPC
LCTL  A(G)  S(A)  D(C)  F(S)  G    TAB | ESC   H     J(S)  K(C)  L(A)  ;(G)  '
LSFT  Z(Num)X     C     V(Nav)B        | N(Nav)M     ,     .     /(Sym)RAW(T)
            ALT   GUI   TAB(V)         | ENT(V)SPC   Func(L)
```
*(G=GUI, A=Alt, C=Ctrl, S=Shift, V=Vertical Key, T=Toggle)*

### 2. Navigation Layer (`_NAV`)
방향키와 마우스 제어 레이어입니다. (`V` 또는 `N` 키 홀드)

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
      -     MS_U  -     -     -     -  | -     HOME  PGUP  PGDN  END   -     -
-     MS_L  MS_D  MS_R  -     WH_U  -  | -     LEFT  DOWN  UP    RGHT  -     -
-     -     WH_D  -     -     -        | -     -     BSPC  DEL   -     -     -
            -     -     -              | -     -     -
```

### 3. Number Pad (`_NUM`)
숫자 입력 레이어입니다. (`Z` 키 홀드) 일반 숫자 키코드를 사용하여 OS 호환성을 높였습니다.

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
      -     -     -     -     -     -  | -     /     7     8     9     -     -
-     -     -     -     -     -     -  | -     *     4     5     6     +     -
-     -     -     -     -     -        | -     0     1     2     3     .     -
            -     -     -              | -     -     -
```

### 4. Symbols (`_SYM`)
특수 기호 레이어입니다. (`G` 또는 `/` 키 홀드)
*(G_SYM은 현재 keymap.c에서 G 키에 적용 준비 중)*

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
      !     @     #     $     %     -  | -     ^     &     *     (     )     `
-     ^     &     *     -     =     -  | -     [     ]     '     "     ;     -
-     ~     _     +     |     \        | -     -     -     -     -     -     -
            -     -     -              | -     -     -
```

### 5. Function Keys (`_FUNC`)
F1 ~ F12 키 레이어입니다. (오른쪽 엄지 가장 우측 키 홀드)

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
      -     -     -     -     -     -  | -     F12   F7    F8    F9    -     -
-     -     -     -     -     -     -  | -     F11   F4    F5    F6    -     -
-     -     -     -     -     -        | -     F10   F1    F2    F3    -     -
            -     -     -              | -     -     -
```

## 🚀 Quick Start (NixOS)

### 1. Build
`qmk_firmware` 폴더 내의 해당 위치로 파일을 동기화한 후 빌드를 수행합니다.
```bash
# 파일 동기화
cp -r keymaps/yongminari ~/qmk_firmware/keyboards/crkbd/keymaps/

# 빌드 실행
cd ~/qmk_firmware
qmk compile -kb crkbd/rev4_1/standard -km yongminari
```

### 2. Flash (Using `dd`)
부트로더 모드(RPI-RP2) 진입 후 `dd` 명령어로 펌웨어를 입힙니다.
- **왼쪽:** `Q` 키를 누른 채 USB 연결
- **오른쪽:** `P` 키를 누른 채 USB 연결

```bash
# 장치 이름(sdX1)은 lsblk로 확인 필수
sudo dd if=~/qmk_firmware/crkbd_rev4_1_standard_yongminari.uf2 of=/dev/sdX1 conv=fdatasync
```

## ⌨️ Keymap Features
- **Home Row Mods (GACS):** `A,S,D,F / J,K,L,;` 키에 GUI, Alt, Ctrl, Shift 적용.
- **Tapping Term:** 200ms.
- **Tapping Optimizations:**
  - `HOLD_ON_OTHER_KEY_PRESS`: 키를 누른 상태에서 다른 키를 누르면 즉시 홀드로 인식 (레이어 전환 속도 향상).
  - `PERMISSIVE_HOLD` 및 `QUICK_TAP_TERM` 적용.
- **Layers:**
  - `_DEFAULT`: 기본 알파 및 Home Row Mods
  - `_NAV`: 방향키, Backspace(M), Delete(Comma)
  - `_NUM`: 숫자 패드 (표준 숫자 키코드)
  - `_SYM`: 특수 기호
  - `_FUNC`: F1~F12 기능키
  - `_RAW`: 게임용 순정 모드 (토글 가능)

## 📌 TODO
- [ ] 레이어별 키 배치 최적화 (사용하면서 보정 필요)
- [ ] 매크로 추가 (한영 전환 등)
- [ ] RGB Matrix 효과 커스텀

## 💡 Notes
- 분할 키보드 통신을 위해 `MASTER_LEFT`가 설정되어 있으므로, 반드시 **왼쪽 키보드**를 컴퓨터에 USB로 연결하여 사용하십시오.
- TRRS 케이블 연결 시 반드시 전원을 끄고 연결하십시오.
