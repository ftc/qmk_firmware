/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 1
#define MATRIX_COLS 5


/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* define if matrix has ghost (lacks anti-ghosting diodes) */
//#define MATRIX_HAS_GHOST

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define USB_MAX_POWER_CONSUMPTION 100

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 3

#define ROTATIONAL_TRANSFORM_ANGLE 20

// If board has a debug LED, you can enable it by defining this
// #define DEBUG_LED_PIN F7

/* PMW33XX Settings */
#define PMW33XX_CS_PIN             B0
#define POINTING_DEVICE_INVERT_Y
#define PLOOPY_DPI_OPTIONS {800, 1000, 1200, 1600, 1800 }
#define PLOOPY_DPI_DEFAULT 2
#define PLOOPY_DPI_MAX 4 // max index in PLOOPY_DPI_OPTIONS
#define PLOOPY_DRAGSCROLL_FIXED 1
#define PLOOPY_DRAGSCROLL_DPI 100
#define PLOOPY_DRAGSCROLL_MOMENTARY
#define PLOOPY_DRAGSCROLL_INVERT
