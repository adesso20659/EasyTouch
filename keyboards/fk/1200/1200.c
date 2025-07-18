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
    { 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , 13       , 14       , NO_LED     },
	{ 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , 29       , 30       , 31       , 32       , NO_LED   , NO_LED     },
	{ 37       , 38       , 39       , 40       , 41       , 42       , 43       , 44       , 45       , 46       , 47       , 48       , 49       , 50       , NO_LED   , NO_LED     },
	{ 55       , 56       , 57       , 58       , 59       , 60       , 61       , 62       , 63       , 64       , 65       , 66       , NO_LED   , 67       , NO_LED   , NO_LED     },
	{ 71       , NO_LED   , 72       , 73       , 74       , 75       , 76       , 77       , 78       , 79       , 80       , 81       , NO_LED   , 82       , 83       , 84         },
	{ 88       , 89       , 90       , NO_LED   , 15       , 91       , 16       , 17       , 18       , 92       , 93       , NO_LED   , 94       , 95       , 96       , 97         },
    { 33       , 34       , 35       , 36       , 51       , 52       , 53       , 68       , 69       , 70       , 54       , 85       , 86       , 98       , 99       , 87         }
},{
    { 0,  10},  { 12, 10}, { 24, 10}, { 36, 10}, { 48, 10}, { 60, 10}, { 72, 10}, { 84, 10}, { 96, 10}, { 108, 10}, { 120, 10}, { 132, 10}, { 144, 10}, { 156, 10}, { 168, 10}, { 180, 10}, { 192, 10},{ 204, 10},{ 224, 10},
    { 0,  20},  { 12, 20}, { 24, 20}, { 36, 20}, { 48, 20}, { 60, 20}, { 72, 20}, { 84, 20}, { 96, 20}, { 108, 20}, { 120, 20}, { 132, 20}, { 144, 20}, { 162, 20},             { 180, 20}, { 192, 20},{ 204, 20},{ 224, 20},
    { 3,  30},  { 18, 30}, { 30, 30}, { 42, 30}, { 54, 30}, { 66, 30}, { 78, 30}, { 90, 30}, { 102,30}, { 114, 30}, { 126, 30}, { 138, 30}, { 150, 30}, { 165, 30},             { 180, 30}, { 192, 30},{ 204, 30},{ 224, 30},
    { 4,  40},             { 20, 40}, { 32, 40}, { 44, 40}, { 56, 40}, { 68, 40}, { 80, 40}, { 92, 40}, { 104, 40}, { 116, 40}, { 128, 40}, { 140, 40},             { 162, 40}, { 180, 40}, { 192, 40},{ 204, 40},
    { 6,  50},             { 25, 50}, { 37, 50}, { 49, 50}, { 61, 50}, { 73, 50}, { 85, 50}, { 97, 50}, { 109, 50}, { 121, 50}, { 133, 50},             { 157, 50}, { 168, 50}, { 180, 50}, { 192, 50},{ 204, 50},{ 224, 50},
    { 0,  60},  { 14, 60}, { 28, 60},                                  { 74, 60},                                   { 120, 60}, { 132, 60}, { 144, 60}, { 156, 60}, { 168, 60}, { 180, 60}, { 192, 60},{ 204, 60}
}, {
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,  1,
    1,  1,  1,  1,      1,  1,  1,  1,  1,      1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1
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
