/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "test.h"

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

enum custom_keycodes {
    KC_MISSION_CONTROL = USER00,
    KC_LAUNCHPAD,
    KC_TASK_VIEW,
    KC_FILE_EXPLORER,
};

typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[2];
} key_combination_t;

key_combination_t key_comb_list[2] = {
    {2, {KC_LWIN, KC_TAB}},
    {2, {KC_LWIN, KC_E}}
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_TASK KC_TASK_VIEW
#define KC_FLXP KC_FILE_EXPLORER

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_82(
        MO(MAC_FN),             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_DEL,   KC_MUTE,
        KC_GRV,     KC_1,       KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_MINS,  KC_EQL,   KC_7,     KC_8,     KC_9,       KC_0,     KC_BSPC,            KC_PGUP,
        KC_TAB,     KC_Q,       KC_W,     KC_F,     KC_P,     KC_B,     KC_QUOT,  KC_J,     KC_L,     KC_U,     KC_Y,     KC_LBRC,    KC_RBRC,  KC_SCLN,            KC_PGDN,
        KC_ESC,     KC_A,       KC_R,     KC_S,     KC_T,     KC_G,     KC_BSLS,  KC_M,     KC_N,     KC_E,     KC_I,     KC_O,                 KC_ENT,             KC_HOME,
        KC_LSPO,                KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,     KC_SLSH,  KC_K,     KC_H,     KC_COMM,  KC_DOT,     KC_RSPC,  KC_UP,
        KC_LCPO,    KC_LAPO,    KC_LGUI,                                KC_SPC,                                 KC_RGUI,  KC_RAPC,    KC_RCPC,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_ansi_82(
        KC_TRNS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,   KC_TRNS,  RGB_TOG,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,            KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

    [WIN_BASE] = LAYOUT_ansi_82(
        MO(WIN_FN),           KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
        KC_GRV,     KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_MINS,  KC_EQL,   KC_7,     KC_8,     KC_9,       KC_0,     KC_BSPC,            KC_PGUP,
        KC_TAB,     KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     KC_QUOT,  KC_J,     KC_L,     KC_U,     KC_Y,     KC_LBRC,    KC_RBRC,  KC_SCLN,            KC_PGDN,
        KC_ESC,     KC_A,     KC_R,     KC_S,     KC_T,     KC_G,     KC_BSLS,  KC_M,     KC_N,     KC_E,     KC_I,     KC_O,                 KC_ENT,             KC_HOME,
        KC_LSPO,              KC_X,     KC_C,     KC_D,     KC_V,     KC_Z,     KC_SLSH,  KC_K,     KC_H,     KC_COMM,  KC_DOT,     KC_RSPC,  KC_UP,
        KC_LCPO,    KC_LGUI,  KC_LAPO,                                KC_SPC,                                 KC_RAPC,  KC_RGUI,    KC_RCPC,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        KC_TRNS,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,    KC_VOLD,  KC_VOLU,  KC_TRNS,  RGB_TOG,
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,            KC_TRNS,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  NK_TOGG,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,            KC_TRNS,
        KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,            KC_TRNS,
        KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,              KC_TRNS,  KC_TRNS,
        KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif

bool dip_switch_update_user(uint8_t index, bool active) {
    system_switch_state_report(index, active);
    return true;
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_TASK:
        case KC_FLXP:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            } else {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++) {
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
                }
            }
            return false;  // Skip all further processing of this key
        case KC_1 ... KC_0:
        case KC_SCLN:
            if (record->event.pressed) {
              if (mod_state & MOD_MASK_SHIFT) {
                // We're explicitly shifting; send the unshifted code.
                // autoshift will handle the non-shifted and auto-shifted
                // variants.
                del_mods(MOD_MASK_SHIFT);
                register_code(keycode);
                set_mods(mod_state);
                return false;
              } else if (mod_state) {
                // We're in the middle of some command chord: autoshift doesn't
                // apply.
                // NOTE: It probably makes sense to vary the behavior here based
                // on AUTO_SHIFT_MODIFIERS
                register_code16(S(keycode));
                return false;
              }
            }
        default:
            return true;   // Process all other keycodes normally
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_1 ... KC_0:
        case KC_SCLN:
            register_code16(shifted ? keycode : S(keycode));
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_1 ... KC_0:
        case KC_SCLN:
            unregister_code16(shifted ? keycode : S(keycode));
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
