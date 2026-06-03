#include QMK_KEYBOARD_H

/* Layer Definitions */
enum layers {
    _DEFAULT = 0,
    _NAV,
    _NUM,
    _SYM,
    _FUNC,
    _RAW,
    _EXTRA
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

/* Layer Tap Aliases on Alphas */
#define V_NAV   LT(_NAV, KC_V)
#define N_NAV   LT(_NAV, KC_N)
#define Z_SFT   MT(MOD_LSFT, KC_Z)
#define SL_SFT  MT(MOD_RSFT, KC_SLSH)
#define C_NUM   LT(_NUM, KC_C)
#define COMM_SYM LT(_SYM, KC_COMM)
#define G_SYM   LT(_SYM, KC_G)
#define Z_NUM   LT(_NUM, KC_Z)
#define SL_SYM  LT(_SYM, KC_SLSH)
#define SPC_EXT LT(_EXTRA, KC_SPC)

/* Special Aliases */
#define ESC_CTL CTL_T(KC_ESC)
#define LA_FUNC LT(_FUNC, KC_LALT)

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
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ENT,    KC_DEL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        /* Row 1: Left & Right */
        KC_LCTL, A_MET,   S_ALT,   D_CTL,   F_SFT,   G_SYM,   KC_TAB,    TG(_RAW),KC_H,    J_SFT,   K_CTL,   L_ALT,   CLN_MET, KC_QUOT,
        /* Row 2: Left & Right (6 keys each) */
        KC_LSFT, Z_SFT,   KC_X,    C_NUM,   V_NAV,   KC_B,               N_NAV,   KC_M,    COMM_SYM, KC_DOT,  SL_SFT,  KC_RSFT,
        /* Thumb Row: Left & Right (3 keys each) */
        LA_FUNC, KC_LGUI, KC_TAB,                                        KC_ENT,  SPC_EXT, KC_RALT
    ),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
        /* Row 0: Left & Right */
        _______, MS_ACL0, MS_WH_L, MS_WH_D, MS_WH_U, MS_WH_R, _______,   _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______,
        /* Row 1: Left & Right */
        _______, MS_ACL2, MS_L,    MS_D,    MS_U,    MS_R,    _______,   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        /* Row 2: Left & Right */
        _______, _______, MS_BTN1, MS_BTN3, MS_BTN2, _______,               _______, KC_BSPC, KC_DEL,  _______, _______, _______,
        /* Thumb Row: Left & Right */
        _______, _______, _______,                                        _______, _______, _______
    ),

    [_NUM] = LAYOUT_split_3x6_3_ex2(
        _______, _______, _______, _______, _______, _______, _______,   _______, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, _______, _______, _______, _______, _______,               _______, KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
        _______, _______, _______,                                        _______, KC_0,    _______
    ),

    [_SYM] = LAYOUT_split_3x6_3_ex2(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,   _______, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_GRV,  _______,
        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______,   _______, KC_LPRN, KC_RPRN, KC_QUOT, KC_DQT,  KC_COLN, _______,
        _______, KC_TILD, KC_UNDS, KC_PLUS, KC_PIPE, KC_BSLS,               _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                                        _______, _______, _______
    ),

    [_FUNC] = LAYOUT_split_3x6_3_ex2(
        _______, _______, _______, _______, _______, _______, _______,   _______, KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______,
        _______, _______, _______, _______, _______, _______,               KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, _______,
        _______, _______, _______,                                        _______, _______, _______
    ),

    [_RAW] = LAYOUT_split_3x6_3_ex2(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ENT,    KC_DEL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,    TG(_RAW),KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LALT, KC_LGUI, KC_TAB,                                        KC_ENT,  KC_SPC,  KC_RALT
    ),

    [_EXTRA] = LAYOUT_split_3x6_3_ex2(
        _______, KC_TAB,  _______, _______, _______, _______, _______,   _______, RM_TOGG, RM_NEXT, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, RM_HUEU, RM_SATU, RM_VALU, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,               RM_HUED, RM_SATD, RM_VALD, _______, _______, _______,
        _______, _______, _______,                                        _______, _______, _______
    )
};

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
