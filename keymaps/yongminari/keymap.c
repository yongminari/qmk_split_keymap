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

#define K_CTL   MT(MOD_RCTL, KC_K)
#define L_ALT   MT(MOD_RALT, KC_L)
#define CLN_MET MT(MOD_RGUI, KC_SCLN)

/* Thumb Row Layer Tap Aliases */
#define TAB_FUNC LT(_FUNC, KC_TAB)
#define ENT_FUNC LT(_FUNC, KC_ENT)
#define SPC_NAV  LT(_NAV, KC_SPC)
#define TAB_NUM  LT(_NUM, KC_TAB)

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
        TAB_NUM, SPC_NAV, KC_LSFT,                                       KC_RSFT, SPC_NAV, TAB_NUM
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
    
    // 외각 전용 Shift 키(KC_LSFT, KC_RSFT)의 더블탭을 감지하여 Caps Word 활성화
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
        case K_CTL:
        case L_ALT:
        case CLN_MET:
            return 175; // 홈로우 모디파이어 키: 175ms (더 빠르고 민첩한 반응)
        case TAB_FUNC:
        case ENT_FUNC:
        case SPC_NAV:
        case TAB_NUM:
            return 175; // 엄지 레이어-탭 키: 175ms (실수 유발 방지 및 여유로운 입력)
        default:
            return TAPPING_TERM; // 기본값: 180ms
    }
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record, uint16_t other_keycode, keyrecord_t *other_record) {
    // 모디파이어 키들끼리의 조합(예: Ctrl + Shift, Super + Alt 등)은 같은 손이더라도 무조건 Hold로 인정합니다.
    switch (other_keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
        case KC_LCTL: case KC_LSFT: case KC_LALT: case KC_LGUI:
        case KC_RCTL: case KC_RSFT: case KC_RALT: case KC_RGUI:
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
    if (!is_flow_tap_key(keycode) || !is_flow_tap_key(prev_keycode)) {
        return 0; // 흐름 입력 대상 키가 아니면 Flow Tap 비활성화 (get_flow_tap_term이 정의되면 is_flow_tap_key보다 우선하기 때문)
    }
    return FLOW_TAP_TERM; // 기본값: 120ms (config.h 정의)
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return QUICK_TAP_TERM; // 기본값 (175ms)
    }
}


