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

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x3434
#define MANUFACTURER    Keychron
#define PRODUCT         Keychron Q2

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 15

/* key matrix pins */
#define MATRIX_ROW_PINS \
    { B4, B3, A15, A14, A13 }
#define MATRIX_COL_PINS \
    { C14, C15, A0, A1, A2, A3, A4, A5, A6, A7, B0, B1, A8, A9, H3 }

/* If uses PH3 with a stronger pull resistor then the following definition should be included */
#define MATRIX_UNSELECT_DRIVE_HIGH

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* RGB Matrix Driver Configuration */
#define DRIVER_COUNT 2
#define DRIVER_ADDR_1 0b1110111
#define DRIVER_ADDR_2 0b1110100

/* Scan phase of led driver set as MSKPHASE_9CHANNEL(defined as 0x03 in CKLED2001.h) */
#define PHASE_CHANNEL MSKPHASE_9CHANNEL
#define CONSTANT_CURRENT_STEP \
    { 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60, 0xCA, 0xCA, 0x60 }

/* Disable DIP switch in matrix data */
#define MATRIX_MASKED

/* DIP switch */
#define DIP_SWITCH_MATRIX_GRID  { {4,4} }
#define SCAN_COUNT_MAX 100

/* Turn off effects when suspended */
#define RGB_DISABLE_WHEN_USB_SUSPENDED

/* Encoder Configuration */
#define ENCODERS_PAD_A { A10 }
#define ENCODERS_PAD_B { B5 }
#define ENCODER_RESOLUTION 4
#define ENCODER_DEFAULT_POS 0x3

/* We have 2KB EEPROM size on STM32L432 */
#define WEAR_LEVELING_LOGICAL_SIZE 2048
#define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)

// RGB Matrix Animation modes. Explicitly enabled
// For full list of effects, see:
// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
// #define ENABLE_RGB_MATRIX_ALPHAS_MODS
// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_BREATHING
// #define ENABLE_RGB_MATRIX_BAND_SAT
// #define ENABLE_RGB_MATRIX_BAND_VAL
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define ENABLE_RGB_MATRIX_CYCLE_ALL
#define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#define ENABLE_RGB_MATRIX_DUAL_BEACON
#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
// #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define ENABLE_RGB_MATRIX_RAINDROPS
// #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define ENABLE_RGB_MATRIX_HUE_BREATHING
// #define ENABLE_RGB_MATRIX_HUE_PENDULUM
// #define ENABLE_RGB_MATRIX_HUE_WAVE
// #define ENABLE_RGB_MATRIX_PIXEL_RAIN
// #define ENABLE_RGB_MATRIX_PIXEL_FLOW
// #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
// enabled only if RGB_MATRIX_FRAMEBUFFER_EFFECTS is defined
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
// enabled only of RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is defined
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define ENABLE_RGB_MATRIX_SPLASH
#define ENABLE_RGB_MATRIX_MULTISPLASH
#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
// #define RGB_MATRIX_KEYPRESSES

/* Enable receive custom command from host */
#define RAW_HID_CMD 0xAB
