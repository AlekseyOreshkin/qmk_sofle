// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [2] = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [3] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [4] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
};
#endif

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _GAME,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_GAME,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_ACPP, // Arrow c++
};

// Tap dance declarations
enum {
    TD_RALT_WIN,
    TD_ESC_CAPS,
    TD_GUI_UPPR,
    TD_APP__LWR,
};

// Tap dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_RALT_WIN] = ACTION_TAP_DANCE_DOUBLE(KC_RALT, KC_RGUI),
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
    [TD_GUI_UPPR] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LGUI, 2),
    [TD_APP__LWR] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_APP , 1),
};

#define TD_RALT TD(TD_RALT_WIN)
#define TD_ESC  TD(TD_ESC_CAPS)
#define TD_GUI  TD(TD_GUI_UPPR)
#define TD_APP  TD(TD_APP__LWR)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮                   ╭──────────────────────────────────────────────────────╮
          KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_RBRC,
          KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,
          KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
          KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  MS_BTN2,  KC_MUTE,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LCTL, KC_LALT, TD_GUI, TL_LOWR,  KC_SPC,                       KC_ENT, TL_UPPR, TD_APP, KC_RALT, KC_RCTL
  // ╰──────────────────────────────────────────────────────╯                   ╰──────────────────────────────────────────────────────╯
),
[_GAME] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮                   ╭──────────────────────────────────────────────────────╮
          KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_RBRC,
          KC_ESC,    KC_T,   KC_Q,   KC_W,    KC_E,    KC_R,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC,
          KC_TAB,    KC_G,   KC_A,   KC_S,    KC_D,    KC_F,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
          KC_LSFT,   KC_B,   KC_Z,   KC_X,    KC_C,    KC_V,  MS_BTN2,  KC_MUTE,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LCTL, KC_LALT, TD_GUI, TL_LOWR,  KC_SPC,                       KC_ENT, TL_UPPR, TD_APP, KC_RALT, KC_RCTL
  // ╰──────────────────────────────────────────────────────╯                   ╰──────────────────────────────────────────────────────╯
),
[_LOWER] = LAYOUT(
 // ╭──────────────────────────────────────────────────────╮                   ╭──────────────────────────────────────────────────────╮
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
       KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_F12,
      KC_CAPS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE,
      _______,  KC_EQL, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,  MS_BTN3,  KC_MPLY,  KC_LBRC, KC_RBRC, KC_ACPP, KC_UNDS, KC_BSLS, _______,
               _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______
 // ╰──────────────────────────────────────────────────────╯                   ╰──────────────────────────────────────────────────────╯
),
[_RAISE] = LAYOUT(
 // ╭──────────────────────────────────────────────────────╮                   ╭──────────────────────────────────────────────────────╮
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
       KC_ESC, KC_PSCR, KC_SCRL, KC_PAUS, XXXXXXX, XXXXXXX,                       KC_DEL, KC_PGUP,   KC_UP, KC_PGDN,  KC_INS, KC_HOME,
       KC_TAB, KC_LALT, KC_LCTL, KC_LSFT,G(S(KC_S)),KC_CAPS,                     KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT,  KC_DEL,  KC_END,
      _______, C(KC_Z), C(KC_X), C(KC_C), G(KC_V),G(KC_SPC), _______,  _______, KC_LSTRT,KC_PRVWD,KC_NXTWD, KC_LEND, XXXXXXX, _______,
                _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______
 // ╰──────────────────────────────────────────────────────╯                   ╰──────────────────────────────────────────────────────╯
),
[_ADJUST] = LAYOUT(
 // ╭──────────────────────────────────────────────────────╮                   ╭──────────────────────────────────────────────────────╮
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      QK_BOOT, XXXXXXX,KC_QWERTY,KC_GAME, CG_TOGG, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
      XXXXXXX, XXXXXXX, CG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
               _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______
 // ╰──────────────────────────────────────────────────────╯                   ╰──────────────────────────────────────────────────────╯
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                layer_off(_GAME);
                set_single_persistent_default_layer(_QWERTY);
                layer_on(_QWERTY);
            }
            return false;
        case KC_GAME:
            if (record->event.pressed) {
                layer_off(_QWERTY);
                set_single_persistent_default_layer(_GAME);
                layer_on(_GAME);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_ACPP:
            if (record->event.pressed) {
                SEND_STRING_DELAY("->", 10);
            }
            break;
    }
    return true;
}
