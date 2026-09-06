#include QMK_KEYBOARD_H

/* Layer Definitions */
enum layers {
    _DEFAULT = 0,
    _NAV,
    _NUM,
    _FUNC
};

/* Home Row Mods Aliases */
#define S_MET   MT(MOD_LGUI, KC_S)
#define D_ALT   MT(MOD_LALT, KC_D)
#define F_CTL   MT(MOD_LCTL, KC_F)

#define J_CTL   MT(MOD_LCTL, KC_J)
#define K_ALT   MT(MOD_LALT, KC_K)
#define L_MET   MT(MOD_LGUI, KC_L)

/* Shift Combo Mods Aliases */
#define W_SMET  LSG_T(KC_W)
#define E_SALT  LSA_T(KC_E)
#define R_SCTL  LCS_T(KC_R)

#define U_SCTL  LCS_T(KC_U)
#define I_SALT  LSA_T(KC_I)
#define O_SMET  LSG_T(KC_O)

/* Layer Tap Aliases */
#define T_NSFT   LT(_NAV, KC_T)
#define Y_NSFT   LT(_NAV, KC_Y)
#define V_FUNC   LT(_FUNC, KC_V)
#define M_FUNC   LT(_FUNC, KC_M)
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
        _______, KC_Q,    W_SMET,  E_SALT,  R_SCTL,  T_NSFT,  KC_NO,     KC_NO,   Y_NSFT,  U_SCTL,  I_SALT,  O_SMET,  KC_P,    _______,
        /* Row 1: Left & Right */
        _______, KC_A,    S_MET,   D_ALT,   F_CTL,   KC_G,    KC_NO,     KC_NO,   KC_H,    J_CTL,   K_ALT,   L_MET,   KC_SCLN, _______,
        /* Row 2: Left & Right (6 keys each) */
        _______, KC_Z,    KC_X,    KC_C,    V_FUNC,  KC_B,               KC_N,    M_FUNC,  KC_COMM, KC_DOT,  KC_SLSH, _______,
        /* Thumb Row: Left & Right (3 keys each) */
        TAB_NUM, SPC_NAV, KC_LSFT,                                       KC_RSFT, SPC_NAV, TAB_NUM
    ),


    [_NAV] = LAYOUT_split_3x6_3_ex2(
        /* Row 0: Left & Right */
        _______, KC_ESC,  MS_WH_L, MS_WH_U, MS_WH_D, MS_WH_R, KC_NO,     KC_NO,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
        /* Row 1: Left & Right */
        _______, _______, MS_L,    MS_U,    MS_D,    MS_R,    KC_NO,     KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        /* Row 2: Left & Right */
        _______, _______, MS_BTN1, MS_BTN3, MS_BTN2, _______,               KC_ENT,  KC_BSPC, KC_DEL,  _______, _______, _______,
        /* Thumb Row: Left & Right */
        _______, _______, _______,                                        _______, KC_RALT, KC_RCTL
    ),

    [_NUM] = LAYOUT_split_3x6_3_ex2(
        /* Row 0: Left & Right */
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_NO,     KC_NO,   KC_LCBR, KC_7,    KC_8,    KC_9,    KC_GRV,  _______,
        /* Row 1: Left & Right */
        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  KC_NO,     KC_NO,   KC_RCBR, KC_4,    KC_5,    KC_6,    KC_QUOT, _______,
        /* Row 2: Left & Right (6 keys each) */
        _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_BSLS,               KC_TILD, KC_1,    KC_2,    KC_3,    KC_DQUO,  _______,
        /* Thumb Row: Left & Right (3 keys each) */
        KC_UNDS, KC_PLUS, KC_PIPE,                                        KC_PERC, KC_0,    KC_DOT
    ),

    [_FUNC] = LAYOUT_split_3x6_3_ex2(
        /* Row 0: Left & Right */
        _______, KC_VOLU, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, _______,
        /* Row 1: Left & Right */
        _______, KC_VOLD, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_F11,  KC_F4,   KC_F5,   KC_F6,   S(KC_PSCR), _______,
        /* Row 2: Left & Right (6 keys each) */
        _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, _______,
        /* Thumb Row: Left & Right (3 keys each) */
        _______, _______, _______,                                        _______, _______, _______
    )
};

static uint8_t nav_shift_hold_count = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CAPS_WORD_ENABLE
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
#endif

    // T/Y를 홀드하면 Nav 레이어와 Shift를 동시에 활성화
    if ((keycode == T_NSFT || keycode == Y_NSFT) && !record->tap.count) {
        if (record->event.pressed) {
            if (nav_shift_hold_count++ == 0) {
                add_weak_mods(MOD_BIT(KC_LSFT));
                send_keyboard_report();
            }
        } else if (nav_shift_hold_count > 0 && --nav_shift_hold_count == 0) {
            del_weak_mods(MOD_BIT(KC_LSFT));
            send_keyboard_report();
        }
    }

    return true;
}

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
    return keycode == SPC_NAV || keycode == TAB_NUM ? THUMB_TAPPING_TERM : TAPPING_TERM;
}
