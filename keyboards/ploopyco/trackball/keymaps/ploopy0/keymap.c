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
#include QMK_KEYBOARD_H
#include "trackball.h"
//#include<stdio.h>

// safe range starts at `PLOOPY_SAFE_RANGE` instead.
//
enum custom_keycodes {
    QMKBEST = PLOOPY_SAFE_RANGE,
    UI_CPY_SCROLL,
    UI_PST,
    UI_BTN2_L2,
    UI_DPI_UP,
    UI_DPI_DOWN
};

//void process_mouise_user(report_mouse_t mouse_report, int16_t x, int16_t y){
//    char buffer[20];
//    sprintf(buffer,"%i ", (int)(mouse_report->x));
//    SEND_STRING(buffer);
//}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t scroll_timer;
    static uint16_t right_click_timer;
    static bool right_click_held = false;
    static bool cpy_scroll_held = false;
    static uint8_t current_dpi = PLOOPY_DPI_DEFAULT;
    keyrecord_t record_press = {
            .event = {
                .pressed = 1,
            },
        };
    keyrecord_t record_un_press = {
            .event = {
                .pressed = 0,
            },
        };
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case UI_CPY_SCROLL:
            if(!right_click_held){
                if(record->event.pressed) {
                    scroll_timer = timer_read();
                    process_record_kb(DRAG_SCROLL, &record_press);
                    cpy_scroll_held = true;
                    //register_code16(DRAG_SCROLL);
                    //SEND_STRING("press");
                }else {
                    //unregister_code16(DRAG_SCROLL);
                    process_record_kb(DRAG_SCROLL, &record_un_press);
                    cpy_scroll_held = false;
                    if(timer_elapsed(scroll_timer) < 200){
                        SEND_STRING(SS_LGUI("c"));
                    }
                    //SEND_STRING("release");
                }
            }else{
                    register_code(KC_LEFT);
                    unregister_code(KC_LEFT);
            }
            break;
        case UI_PST:

            if(!right_click_held){
                if(record->event.pressed) {
                    if(cpy_scroll_held){
                        //SEND_STRING(SS_LCTL(SS_TAP(KC_UP)));
                        //SS_TAP(LCTL(KC_UP));
                        register_code(KC_LCTL);
                        register_code(KC_UP);
                        unregister_code(KC_UP);
                        unregister_code(KC_LCTL);
                    }else{
                        SEND_STRING(SS_LGUI("v"));
                    }
                }
            }else{
                register_code(KC_RIGHT);
                unregister_code(KC_RIGHT);
            }
            break;
        case UI_BTN2_L2:
            if(record->event.pressed){
                right_click_timer = timer_read();
                right_click_held = true;
            }else{
                right_click_held = false;
                if(timer_elapsed(right_click_timer) < 200){
                    register_code(KC_BTN2);
                    unregister_code(KC_BTN2);
                }
            }
            break;
        case UI_DPI_UP:
            if(current_dpi < PLOOPY_DPI_MAX){
                current_dpi += 1;
            }
            pointing_device_set_cpi(dpi_array[current_dpi]);
            break;
        case UI_DPI_DOWN:
            if(current_dpi > 0){
                current_dpi -= 1;
            }
            pointing_device_set_cpi(dpi_array[current_dpi]);
            break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_BTN1, LT(3,KC_BTN3), LT(1,KC_BTN2),
          UI_CPY_SCROLL, UI_PST
    ),
    [1] = LAYOUT( /*Switch Desktops*/
        KC_BTN1, KC_BTN3, KC_BTN2,
          LCTL(KC_LEFT), LCTL(KC_RIGHT)
    ),
    [3] = LAYOUT(
        KC_BTN1, KC_BTN3, KC_BTN2,
          UI_DPI_DOWN, UI_DPI_UP
    )
};
