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

    // NOTE: Flip codes here are defined as an offset from KC_1 to FC_1.
    // Semicolon has to be set explicitly here to avoid making a ton of extra
    // symbols.
    FC_1,
    FC_2,
    FC_3,
    FC_4,
    FC_5,
    FC_6,
    FC_7,
    FC_8,
    FC_9,
    FC_0,

    FC_SCLN = FC_1+21
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
        MO(MAC_FN), KC_BRID,    KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_DEL,   KC_MUTE,
        KC_GRV,     FC_1,       FC_2,     FC_3,     FC_4,     FC_5,     FC_6,     KC_MINS,  KC_EQL,   FC_7,     FC_8,     FC_9,       FC_0,     KC_BSPC,            KC_PGUP,
        KC_TAB,     KC_Q,       KC_W,     KC_F,     KC_P,     KC_B,     KC_QUOT,  KC_J,     KC_L,     KC_U,     KC_Y,     KC_LBRC,    KC_RBRC,  FC_SCLN,            KC_PGDN,
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
        MO(WIN_FN), KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,   KC_MUTE,
        KC_GRV,     FC_1,     FC_2,     FC_3,     FC_4,     FC_5,     FC_6,     KC_MINS,  KC_EQL,   FC_7,     FC_8,     FC_9,       FC_0,     KC_BSPC,            KC_PGUP,
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
uint16_t real_code;
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
        case FC_1:
        case FC_2:
        case FC_3:
        case FC_4:
        case FC_5:
        case FC_6:
        case FC_7:
        case FC_8:
        case FC_9:
        case FC_0:
        case FC_SCLN:
            real_code = KC_1 + (keycode - FC_1);
            if (record->event.pressed) {
              if (mod_state & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
              } else {
                add_mods(MOD_LSFT);
              }
              register_code(real_code);
              set_mods(mod_state);
            } else {
              unregister_code(real_code);
            }
            return false;
        default:
            return true;   // Process all other keycodes normally
    }
}
