// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers { QWERTY, LOWER, RAISE, NUMERIC, ADJUST };
enum custom_keycodes { KC_ACPP = QK_USER };

#define ESC_GRV  LT(0, KC_ESC)
#define BRC_PAIR LT(0, KC_LBRC)
#define CTL_Z    LCTL_T(KC_Z)
#define ALT_X    LALT_T(KC_X)
#define GUI_C    LGUI_T(KC_C)
#define ALT_DOT  LALT_T(KC_DOT)
#define CTL_SLS  LCTL_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [QWERTY] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        ESC_GRV, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, BRC_PAIR,
        KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
        KC_LSFT, CTL_Z, ALT_X, GUI_C, KC_V, KC_B, KC_NO, KC_NO, KC_N, KC_M, KC_COMM, ALT_DOT, CTL_SLS, KC_RSFT,
        KC_NO, KC_NO, MO(NUMERIC), MO(LOWER), KC_SPC, KC_ENT, MO(RAISE), KC_LGUI, KC_NO, KC_NO
    ),
    [LOWER] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS,
        KC_CAPS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
        KC_TRNS, KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_ACPP, KC_UNDS, KC_BSLS, KC_TRNS,
        KC_NO, KC_NO, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_NO, KC_NO
    ),
    [RAISE] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        KC_TRNS, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_NO, KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
        KC_NO, KC_NO, KC_LCTL, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_NO, KC_NO
    ),
    [NUMERIC] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NUM, KC_PSLS, KC_PAST, KC_P7, KC_P8, KC_P9, KC_INS, KC_NO, KC_NO, KC_PSCR, KC_SCRL, KC_PAUS,
        KC_PENT, KC_PMNS, KC_PPLS, KC_P4, KC_P5, KC_P6, KC_BSPC, KC_PGUP, KC_UP, KC_PGDN, KC_HOME, KC_BSPC,
        KC_TRNS, KC_PDOT, KC_P0, KC_P1, KC_P2, KC_P3, KC_NO, KC_NO, KC_DEL, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS,
        KC_NO, KC_NO, KC_TRNS, KC_LALT, KC_TRNS, KC_TRNS, KC_LALT, KC_LCTL, KC_NO, KC_NO
    ),
    [ADJUST] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        EE_CLR, QK_BOOT, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_MRWD, KC_MPLY, KC_MFFD, KC_MNXT, KC_VOLU,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRIU, KC_VOLD,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BRID, KC_MUTE,
        KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO
    ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [QWERTY]  = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [LOWER]   = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [RAISE]   = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [NUMERIC] = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
    [ADJUST]  = { ENCODER_CCW_CW(KC_TRNS, KC_TRNS), ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LOWER, RAISE, ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ESC_GRV:
        case BRC_PAIR:
            if (record->tap.count) {
                return true;
            }
            // Use QMK's tap-hold decision and suppress the dummy layer action.
            if (record->event.pressed) {
                register_code16(keycode == ESC_GRV ? KC_GRV : KC_RBRC);
            } else {
                unregister_code16(keycode == ESC_GRV ? KC_GRV : KC_RBRC);
            }
            return false;
        case KC_ACPP:
            if (record->event.pressed) {
                SEND_STRING_DELAY("->", 10);
            }
            return false;
    }
    return true;
}
