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
    { 70,     71,     72,     73,     74,     75,     30,     31,     32,     33,     34,     35,     36,      0,      1,      2     },
    { 76,     77,     78,     79,     80,     81,     82,     37,     38,     39,     40,     41,     42,     43,      3,      4     },
    { 83,     84,     85,     86,     87,     88,     44,     45,     46,     47,     48,     49,     50,     51,     10,     11     },
    { 89,     90,     91,     92,     93,     94,     52,     53,     54,     55,     56,     57,     NO_LED, 58,      5,     12     },
    { 95,     NO_LED, 96,     97,     98,     99,    100,     59,     60,     61,     62,     63,     NO_LED, 64,     20,     21     },
    {101,    102,    103,    104,    NO_LED, 105,     NO_LED, 65,     NO_LED, 66,     67,     68,     69,     24,     25,     26     },
    {  6,      7,      8,      9,     13,     14,     15,     17,     18,     19,     16,     22,     23,     27,     28,     29     },
}, {
    { 145,10}, { 155,10}, { 165,10},
    { 145,20}, { 155,20}, { 165,20}, { 175, 20}, { 185, 20}, { 195, 20}, { 205, 20},
    { 145,30}, { 155,30}, { 165,30}, { 175, 30}, { 185, 30}, { 195, 30}, { 205, 30},
                                     { 175, 40}, { 185, 40}, { 195, 40},
               { 155,50},            { 175, 50}, { 185, 50}, { 195, 50},
    { 145,60}, { 155,60}, { 165,60},             { 180, 60}, { 195, 60}, { 205, 60},

    { 75, 10}, { 85, 10}, { 95, 10}, { 105, 10}, { 115, 10}, { 125, 10}, { 135, 10},
    { 70, 20}, { 80, 20}, { 90, 20}, { 100, 20}, { 110, 20}, { 120, 20}, { 135, 20},
    { 65, 30}, { 75, 30}, { 85, 30}, { 95,  30}, { 105, 30}, { 115, 30}, { 125, 30}, { 135, 30},
    { 68, 40}, { 78, 40}, { 88, 40}, { 98,  40}, { 108, 40}, { 118, 40}, { 133, 40},
    { 70, 50}, { 80, 50}, { 90, 50}, { 100, 50}, { 110, 50},             { 130, 50},
               { 75, 60},            { 98,  60}, { 110, 60}, { 125, 60}, { 135, 60},

    { 0,  10},            { 15, 10}, { 25,  10}, { 35,  10}, { 45,  10}, { 55,  10},
    { 0,  20}, { 10, 20}, { 20, 20}, { 30,  20}, { 40,  20}, { 50,  20}, { 60,  20},
    { 2,  30},            { 15, 30}, { 25,  30}, { 35,  30}, { 45,  30}, { 55,  30},
    { 3,  40},            { 17, 40}, { 27,  40}, { 37,  40}, { 47,  40}, { 57,  40},
    { 5,  50},            { 20, 50}, { 30,  50}, { 40,  50}, { 50,  50}, { 60,  50},
    { 0,  60}, { 10, 60}, { 22, 60}, { 35,  60},                         { 55,  60}
}, {
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1,
     1,    1, 1, 1, 1, 1, 1, 1, 1, 1, 1,    1, 1, 1,
     1, 1, 1, 1,    1,    1,    1, 1, 1, 1, 1, 1, 1,
     1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
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
