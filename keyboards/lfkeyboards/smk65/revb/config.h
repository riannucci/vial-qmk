/*
Copyright 2020 LFKeyboards
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x4C46   // "LF"
#define PRODUCT_ID      0x565B   // "s65b"
#define DEVICE_VER      0x0006
#define MANUFACTURER    LFKeyboards
#define PRODUCT         SMK65v2

// RevA
// #define DIODE_DIRECTION COL2ROW
// #define MATRIX_ROWS 5
// #define MATRIX_COLS 16
// #define MATRIX_ROW_PINS {B7, F7, F6, F5, F4}
// #define MATRIX_COL_PINS {F0, F1, D2, D3, D5, D4, D6, D7, B4, B5, B6, C7, B3, B2, B1, B0}

// RevB
#define DIODE_DIRECTION COL2ROW
#define MATRIX_ROWS 5
#define MATRIX_COLS 16
#define MATRIX_ROW_PINS {D6, D7, E0, C3, C4}
#define MATRIX_COL_PINS {F2, C5, E5, E4, B7, B6, B5, B4, B3, B2, B1, B0, E1, C0, C1, C2}
#define RGBLED_NUM 20     // Number of LEDs

//RevB only:

#define AUDIO_VOICES
#define AUDIO_PIN C6

#define BACKLIGHT_LEVELS 8
#define BACKLIGHT_PWM_MAP {8, 16, 40, 55, 70, 128, 200, 255}

#define RGB_DI_PIN C7  // Have to set it to something to get the ws2812 code to compile
#define RGBLED_NUM 20     // Number of LEDs
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 10
#define RGBLIGHT_SAT_STEP 17
#define RGBLIGHT_VAL_STEP 17

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
//#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
