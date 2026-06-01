#include QMK_KEYBOARD_H

/* Layer Definitions */
enum layers {
    _DEFAULT = 0,
    _NAV,
    _NUM,
    _SYM,
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

/* Layer Tap Aliases on Alphas */
#define V_NAV   LT(_NAV, KC_V)
#define N_NAV   LT(_NAV, KC_N)
#define Z_NUM   LT(_NUM, KC_Z)
#define G_SYM   LT(_SYM, KC_G)
#define SL_SYM  LT(_SYM, KC_SLSH)

/* Special Aliases */
#define ESC_CTL CTL_T(KC_ESC)
#define LA_FUNC LT(_FUNC, KC_LALT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_split_3x6_3_ex2(
        /* Row 0: Left & Right */
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_ENT,    KC_DEL,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        /* Row 1: Left & Right */
        KC_LCTL, A_MET,   S_ALT,   D_CTL,   F_SFT,   KC_G,    KC_TAB,    KC_ESC,  KC_H,    J_SFT,   K_CTL,   L_ALT,   CLN_MET, KC_QUOT,
        /* Row 2: Left & Right (6 keys each) */
        KC_LSFT, Z_NUM,   KC_X,    KC_C,    V_NAV,   KC_B,               N_NAV,   KC_M,    KC_COMM, KC_DOT,  SL_SYM,  TG(_RAW),
        /* Thumb Row: Left & Right (3 keys each) */
        KC_LALT, KC_LGUI, KC_TAB,                                        KC_ENT,  KC_SPC,  LA_FUNC
    ),

    [_NAV] = LAYOUT_split_3x6_3_ex2(
        _______, _______, MS_UP,   _______, _______, _______, _______,   _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______,
        _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, MS_WHLU, _______,   _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, MS_WHLD, _______, _______, _______,               _______, KC_BSPC, KC_DEL,  _______, _______, _______,
        _______, _______, _______,                                        _______, _______, _______
    ),

    [_NUM] = LAYOUT_split_3x6_3_ex2(
        _______, _______, _______, _______, _______, _______, _______,   _______, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______, _______,   _______, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
        _______, _______, _______, _______, _______, _______,               KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
        _______, _______, _______,                                        _______, _______, _______
    ),

    [_SYM] = LAYOUT_split_3x6_3_ex2(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,   _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_GRV,
        _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  _______,   _______, KC_LBRC, KC_RBRC, KC_QUOT, KC_DQT,  KC_SCLN, _______,
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
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,    KC_ESC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, TG(_RAW),
        KC_LALT, KC_LGUI, KC_TAB,                                        KC_ENT,  KC_SPC,  KC_RALT
    )
};
