#include QMK_KEYBOARD_H

/* Layer Definitions */
enum layers {
    _DEFAULT = 0,
    _NAV,
    _NUM,
    _FUNC,
    _RAW
};

/* Home Row Mods Aliases */
#define A_MET   MT(MOD_LGUI, KC_A)
#define S_ALT   MT(MOD_LALT, KC_S)
#define D_CTL   MT(MOD_LCTL, KC_D)
#define F_SFT   MT(MOD_LSFT, KC_F)

#define J_SFT   MT(MOD_RSFT, KC_J)
#define K_CTL   MT(MOD_RCTL, KC_K)
#define L_ALT   MT(MOD_RALT, KC_L)
#define CLN_MET MT(MOD_RGUI, KC_SCLN)

/* Thumb Row Layer Tap Aliases */
#define TAB_FUNC LT(_FUNC, KC_TAB)
#define ENT_FUNC LT(_FUNC, KC_ENT)
#define SPC_NAV  LT(_NAV, KC_SPC)
#define TAB_SFT  SFT_T(KC_TAB)
#define ENT_SFT  SFT_T(KC_ENT)


/* Special Aliases */
#define ESC_CTL CTL_T(KC_ESC)

/* Mouse Key Aliases */
#define MS_L    MS_LEFT
#define MS_R    MS_RGHT
#define MS_U    MS_UP
#define MS_D    MS_DOWN
#define MS_WH_L MS_WHLL
#define MS_WH_R MS_WHLR
#define MS_WH_U MS_WHLU
#define MS_WH_D MS_WHLD
#define MS_BTN1 MS_BTN1
#define MS_BTN2 MS_BTN2
#define MS_BTN3 MS_BTN3
#define MS_ACL0 MS_ACL0
#define MS_ACL1 MS_ACL1
#define MS_ACL2 MS_ACL2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_3_ex2(
        /* Row 0: Left & Right */
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TAB,    KC_TAB,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        /* Row 1: Left & Right */
        KC_LCTL, A_MET,   S_ALT,   D_CTL,   KC_F,    KC_G,    ENT_FUNC,  ENT_FUNC,KC_H,   KC_J,    K_CTL,   L_ALT,   CLN_MET, KC_QUOT,
        /* Row 2: Left & Right (6 keys each) */
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        /* Thumb Row: Left & Right (3 keys each) */
        MO(_NUM), MO(_NAV), KC_LSFT,                                       KC_RSFT, SPC_NAV, MO(_NUM)
    ),


    [_NAV] = LAYOUT_split_3x6_3_ex2(
        /* Row 0: Left & Right */
        _______, KC_TAB,  MS_WH_L, MS_WH_D, MS_WH_U, MS_WH_R, TG(_RAW),  TG(_RAW), KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______,
        /* Row 1: Left & Right */
        MS_ACL0, _______, MS_L,    MS_D,    MS_U,    MS_R,    _______,   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        /* Row 2: Left & Right */
        MS_ACL2, _______, MS_BTN1, MS_BTN3, MS_BTN2, _______,               _______, KC_BSPC, KC_DEL,  _______, _______, _______,
        /* Thumb Row: Left & Right */
        _______, _______, _______,                                        _______, _______, _______
    ),

    [_NUM] = LAYOUT_split_3x6_3_ex2(
        /* Row 0: Left & Right */
        KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,   _______, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, KC_TILD,
        /* Row 1: Left & Right */
        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______,   _______, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        /* Row 2: Left & Right (6 keys each) */
        KC_LSFT, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_BSLS,               KC_EQL,  KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
        /* Thumb Row: Left & Right (3 keys each) */
        KC_UNDS, KC_PLUS, KC_PIPE,                                        KC_PERC, KC_0,    _______
    ),

    [_FUNC] = LAYOUT_split_3x6_3_ex2(
        /* Row 0: Left & Right */
        _______, _______, KC_F9,   KC_F8,   KC_F7,   KC_F12,  _______,   _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______,
        /* Row 1: Left & Right */
        _______, _______, KC_F6,   KC_F5,   KC_F4,   KC_F11,  _______,   _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______,
        /* Row 2: Left & Right (6 keys each) */
        _______, _______, KC_F3,   KC_F2,   KC_F1,   KC_F10,               KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, _______,
        /* Thumb Row: Left & Right (3 keys each) */
        _______, _______, _______,                                        _______, _______, _______
    ),

    [_RAW] = LAYOUT_split_3x6_3_ex2(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ENT,    KC_DEL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,    TG(_RAW),KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LALT, KC_LGUI, KC_TAB,                                        KC_ENT,  KC_SPC,  KC_RALT
    )
};

#ifdef CAPS_WORD_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t shift_tap_timer = 0;
    
    // 외각 핑크색 전용 Shift 키(KC_LSFT, KC_RSFT)의 더블탭을 감지하여 Caps Word 활성화
    // 홈로우 Shift(F_SFT, J_SFT)는 한글 연타(예: 'ㄹㄹ') 시 의도치 않은 작동을 막기 위해 제외
    if (keycode == KC_LSFT || keycode == KC_RSFT) {
        if (record->event.pressed) {
            if (timer_elapsed(shift_tap_timer) < TAPPING_TERM) {
                caps_word_on();
                shift_tap_timer = 0;
                return false; // Shift 탭 출력을 억제하여 Caps Word 상태로 즉시 돌입
            }
            shift_tap_timer = timer_read();
        }
    }
    return true;
}
#endif

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_user(void) {
    // 엄지 키 6개 전원 표시등 (Corne v4.1 LED 인덱스 기준)
    // 왼쪽 엄지: 0, 7, 8
    // 오른쪽 엄지: 23, 30, 31
    const uint8_t thumb_leds[] = {0, 7, 8, 23, 30, 31};
    
    for (uint8_t i = 0; i < sizeof(thumb_leds); i++) {
        rgb_matrix_set_color(thumb_leds[i], 50, 50, 50);
    }
    return true;
}
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case A_MET:
        case S_ALT:
        case D_CTL:
        case F_SFT:
        case J_SFT:
        case K_CTL:
        case L_ALT:
        case CLN_MET:
            return 175; // 홈로우 모디파이어 키: 175ms (더 빠르고 민첩한 반응)
        case TAB_FUNC:
        case ENT_FUNC:
        case SPC_NAV:
            return 200; // 엄지 레이어-탭 키: 200ms (실수 유발 방지 및 여유로운 입력)
        default:
            return TAPPING_TERM; // 기본값: 180ms
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // 1. 모디파이어 키들끼리의 조합(예: Ctrl + Shift, Super + Alt 등)은 같은 손이더라도 무조건 Hold로 인정합니다.
    switch (other_keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
        case KC_LCTL: case KC_LSFT: case KC_LALT: case KC_LGUI:
        case KC_RCTL: case KC_RSFT: case KC_RALT: case KC_RGUI:
            return true;
    }

    // 2. 엄지 탭-홀드 Shift 키(TAB_SFT, ENT_SFT)는 동일 손의 알파벳 및 기호와 조합될 때도 즉각 Shift(Hold)로 확정시킵니다.
    // (예: 오른손 엄지 ENT_SFT를 홀드하면서 오른손 알파벳을 칠 때 지연이 발생하거나 Enter가 입력되는 현상 방지)
    if (tap_hold_keycode == TAB_SFT || tap_hold_keycode == ENT_SFT) {
        return true;
    }

    // 사용자님은 엄격한 인간공학적 크로스(양손) 입력을 실천하고 계시므로,
    // 알파벳 단축키에 대한 동일 손 구제 예외는 전혀 필요하지 않습니다.
    // 나머지는 전부 엄격한 양손 판정(CHORDAL_HOLD)을 적용합니다.
    return get_chordal_hold_default(tap_hold_record, other_record);
}

bool is_flow_tap_key(uint16_t keycode) {
    // 레이어 탭 키(SPC_NAV, TAB_FUNC, ENT_FUNC 등)는 고속 타이핑 도중에도 즉시 레이어로 진입할 수 있도록 
    // Flow Tap(선행 유휴 시간) 대상에서 완전히 제외시켜 지연 없이 진입하도록 합니다.
    switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return false;
    }

    // 그 외에는 QMK 기본 추출 방식을 사용하여 일반 알파벳 문자와 스페이스바에 대해서만 true를 반환합니다.
    uint16_t tap_keycode = keycode;
    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            tap_keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
            break;
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            tap_keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
            break;
    }

    switch (tap_keycode) {
        case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record, uint16_t prev_keycode) {
    switch (keycode) {
        case F_SFT:
        case J_SFT:
            return 85; // Shift 키의 흐름 입력 대기 시간(Flow Tap Term)을 85ms로 단축
        default:
            return FLOW_TAP_TERM; // 기본값: 120ms (config.h 정의)
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TAB_SFT:
        case ENT_SFT:
            return 0; // 엄지 Shift 키들은 연타 시 단순 탭(Tab/Enter) 연속 입력으로 작동하지 않고 항상 무조건 Shift(Hold)로 즉시 활성화
        default:
            return QUICK_TAP_TERM; // 기본값 (175ms)
    }
}


