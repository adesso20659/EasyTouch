/* Copyright 2023 Finalkey
 * Copyright 2023 LiWenLiu <https://github.com/Linger7857>
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

#include "../../lib/rdr_lib/rdr_common.h"

void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

led_config_t g_led_config = { {
	{ 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , 14       , 15       , 16        },
	{ 17       , 18       , 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , 29       , 30       , 31       , 32        },
	{ 34       , 35       , 36       , 37       , 38       , 39       , 40       , 41       , 42       , 43       , 44       , 45       , 46       , 47       , 48       , 49        },
	{ 51       , 52       , 53       , 54       , 55       , 56       , 57       , 58       , 59       , 60       , 61       , 62       , NO_LED   , 63       , 33       , 50        },
	{ 64       , NO_LED   , 65       , 66       , 67       , 68       , 69       , 70       , 71       , 72       , 73       , 74       , NO_LED   , 75       , 76       , NO_LED    },
	{ 77       , 78       , 79       , NO_LED   , NO_LED   , 80       , 13       , NO_LED   , NO_LED   , 81       , 82       , 83       , 84       , 85       , 86       , 87        }
},{
    { 0 , 10},  { 16, 10},  { 29, 10},  { 42, 10}, { 55, 10}, { 71, 10}, { 84, 10},  { 97,  10}, { 110, 10}, { 123, 10}, { 136, 10}, { 149, 10}, { 163, 10}, { 180, 10}, { 195, 10}, { 208, 10}, { 224, 10},
    { 0 , 20},  { 13, 20},  { 26, 20},  { 39, 20}, { 52, 20}, { 65, 20}, { 78, 20},  { 91,  20}, { 104, 20}, { 117, 20}, { 130, 20}, { 143, 20}, { 157, 20}, { 176, 20}, { 195, 20}, { 208, 20}, { 224, 20},
    { 3 , 30},  { 20, 30},  { 33, 30},  { 46, 30}, { 59, 30}, { 72, 30}, { 85, 30},  { 98,  30}, { 111, 30}, { 124, 30}, { 137, 30}, { 150, 30}, { 163, 30}, { 179, 30}, { 195, 30}, { 208, 30}, { 224, 30},
    { 5 , 40},              { 22, 40},  { 35, 40}, { 48, 40}, { 61, 40}, { 74, 40},  { 87,  40}, { 100, 40}, { 113, 40}, { 126, 40}, { 140, 40}, { 153, 40}, { 172, 40},
    { 5 , 50},              { 28, 50},  { 41, 50}, { 54, 50}, { 67, 50}, { 80, 50},  { 93,  50}, { 106, 50}, { 119, 50}, { 132, 50}, { 145, 50}, { 168, 50},                         { 208, 50},
    { 0 , 60},  { 16, 60},  { 32, 60},                                   { 82, 60},                                      { 130, 60}, { 150, 60}, { 169, 60}, { 180, 60}, { 195, 60}, { 208, 60}, { 224, 60},

    { 225,65},  { 225,65},  { 225,65}
}, {
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,      1,
    1,  1,  1,              1,              1,  1,  1,  1,  1,  1,  1,

    0,  0,  0,
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();
    return false;
}

void notify_usb_device_state_change_user(enum usb_device_state usb_device_state)  {
    if (Keyboard_Info.Key_Mode == QMK_USB_MODE) {
        if(usb_device_state == USB_DEVICE_STATE_CONFIGURED) {
            Usb_If_Ok = true;//usb枚举完成
            Usb_If_Ok_Led = true;
            Usb_If_Ok_Delay = 0;
        } else {
            Usb_If_Ok = false;
		    Usb_If_Ok_Led = false;
        }
    } else {
        Usb_If_Ok = false;
	    Usb_If_Ok_Led = false;
    }
}

void housekeeping_task_user(void) {
    User_Keyboard_Reset();
    es_chibios_user_idle_loop_hook();
}

void board_init(void) {
    User_Keyboard_Init();
}

void keyboard_post_init_user(void) {
    User_Keyboard_Post_Init();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {   /*键盘只要有按键按下就会调用此函数*/
    Usb_Change_Mode_Delay = 0;                                      /*只要有按键就不会进入休眠*/
    Usb_Change_Mode_Wakeup = false;

    return Key_Value_Dispose(keycode, record);
}
