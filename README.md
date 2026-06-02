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
LCTL  A(G)  S(A)  D(C)  F(S)  G    TAB | TG(R) H     J(S)  K(C)  L(A)  ;(G)  '
LSFT  Z(Num)X     C     V(Nav)B        | N(Nav)M     ,     .     /(Sym)RSFT
            ALT   GUI   TAB            | ENT   SPC(E)Func(L)
```
*(G=GUI, A=Alt, C=Ctrl, S=Shift, TG(R)=RAW Toggle, SPC(E)=Extra Layer)*

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
숫자 입력 레이어입니다. (`Z` 키 홀드)

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

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
      !     @     #     $     %     -  | -     [     ]     {     }     `     -
-     ^     &     *     -     =     -  | -     (     )     '     "     :     -
-     ~     _     +     |     \        | -     -     -     -     -     -     -
            -     -     -              | -     -     -
```

### 5. Extra Layer (`_EXTRA`)
엄지 Space 키를 홀드한 상태에서 사용하는 레이어입니다.

```text
Left Side                          | Right Side
-----------------------------------|------------------------------------
      TAB   -     -     -     -     -  | -     -     -     -     -     -     -
-     -     -     -     -     -     -  | -     -     -     -     -     -     -
-     -     -     -     -     -        | -     -     -     -     -     -     -
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
sudo dd if=~/qmk_firmware/crkbd_rev4_1_standard_yongminari.uf2 of=/dev/sdX1 conv=fdatasync status=progress
```

## ⌨️ Keymap Features
- **Home Row Mods (GACS):** `A,S,D,F / J,K,L,;` 키에 GUI, Alt, Ctrl, Shift 적용.
- **Tapping Term:** 200ms.
- **Tapping Optimizations:** 오작동 방지를 위해 `HOLD_ON_OTHER_KEY_PRESS` 및 `PERMISSIVE_HOLD` 제거.
- **Layers:**
  - `_DEFAULT`: 기본 알파 및 Home Row Mods, `G` 키 홀드 시 `_SYM` 레이어 진입.
  - `_NAV`: 방향키, 마우스 제어.
  - `_NUM`: Kanata 스타일 숫자 패드.
  - `_SYM`: Kanata 스타일 특수 기호.
  - `_EXTRA`: **Space 홀드 시 활성화. `Space + Q` 조합으로 `Tab` 입력.**
  - `_RAW`: 홈로우 정지 모드 (오른쪽 검지 안쪽 키로 토글).
- **Key Position Changes:**
  - `LA_FUNC` (F1~F12 레이어): **왼쪽 엄지 바깥쪽**으로 이동. 홀드 시 레이어 진입, 탭 시 Alt.
  - `KC_RALT` (오른쪽 Alt): **오른쪽 엄지 바깥쪽**으로 이동. 단순 Alt 기능만 수행.
  - `TG(_RAW)` (홈로우 정지): **오른쪽 검지 안쪽(8번째 키)**으로 이동 및 모든 레이어 통일.

## 📌 TODO
- [ ] 레이어별 키 배치 최적화 (사용하면서 보정 필요)
- [ ] 매크로 추가 (한영 전환 등)
- [ ] RGB Matrix 효과 커스텀

## 💡 Notes
- 분할 키보드 통신을 위해 `MASTER_LEFT`가 설정되어 있으므로, 반드시 **왼쪽 키보드**를 컴퓨터에 USB로 연결하여 사용하십시오.
- TRRS 케이블 연결 시 반드시 전원을 끄고 연결하십시오.
