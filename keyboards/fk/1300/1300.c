/* Copyright 2023 Finalkey
 * Copyright 2023 LiWenLiu <https://github.com/LiuLiuQMK>
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

#include "../../../lib/rdr_lib/rdr_common.h"

/**********************系统函数***************************/
/*  键盘扫描按键延时 */
void matrix_io_delay(void) {
}

void matrix_output_select_delay(void) {
}

void matrix_output_unselect_delay(uint8_t line, bool key_pressed) {
}

/*****************rgb矩阵驱动初始化********************/
led_config_t g_led_config = { {
    { 0        , 1        , 2        , 3        , 4        , 5        , 6        , 7        , 8        , 9        , 10       , 11       , 12       , 13       , 14       , 15        },
    { 16       , 17       , 18       , 19       , 20       , 21       , 22       , 23       , 24       , 25       , 26       , 27       , 28       , 29       , 30       , 31        },
    { 37       , 38       , 39       , 40       , 41       , 42       , 43       , 44       , 45       , 46       , 47       , 48       , 49       , 50       , 51       , 52        },
    { 58       , 59       , 60       , 61       , 62       , 63       , 64       , 65       , 66       , 67       , 68       , 69       , NO_LED   , 70       , 32       , 53        },
    { 74       , NO_LED   , 75       , 76       , 77       , 78       , 79       , 80       , 81       , 82       , 83       , 84       , NO_LED   , 85       , 86       , 87        },
    { 90       , 91       , 92       , NO_LED   , NO_LED   , 93       , NO_LED   , NO_LED   , NO_LED   , 94       , 95       , 96       , 97       , 98       , 99       , 100       },
    { 33       , 34       , 35       , 36       , 54       , 55       , 56       , 71       , 72       , 73       , 57       , 88       , 89       , 101      , 102      , 103       }
}, {
    // "Fine-tuned" complex configuration
    { 0, 10},  { 20, 10},  { 30, 10}, { 40, 10}, { 50, 10}, { 65, 10},  { 75, 10},  { 85, 10},  { 95, 10},  { 110, 10}, { 120, 10}, { 130, 10}, { 140, 10}, { 155, 10}, { 165, 10}, { 175, 10},
    { 0, 20},  { 10, 20},  { 20, 20}, { 30, 20}, { 40, 20}, { 50, 20},  { 60, 20},  { 70, 20},  { 80, 20},  { 90 , 20}, { 100, 20}, { 110, 20}, { 120, 20}, { 135, 20}, { 155, 20}, { 165, 20}, { 175, 20}, { 190, 20}, { 200, 20}, { 210, 20}, { 224, 20},
    { 2, 30},  { 13, 30},  { 23, 30}, { 33, 30}, { 43, 30}, { 53, 30},  { 63, 30},  { 73, 30},  { 83, 30},  { 93 , 30}, { 103, 30}, { 113, 30}, { 123, 30}, { 138, 30}, { 155, 30}, { 165, 30}, { 175, 30}, { 190, 30}, { 200, 30}, { 210, 30}, { 224, 35},
    { 4, 40},  { 15, 40},  { 25, 40}, { 35, 40}, { 45, 40}, { 55, 40},  { 65, 40},  { 75, 40},  { 85, 40},  { 95 , 40}, { 105, 40}, { 115, 40}, { 133, 40},                                                 { 190, 40}, { 200, 40}, { 210, 40}, 
    { 6, 50},              { 20, 50}, { 30, 50}, { 40, 50}, { 50, 50},  { 60, 50},  { 70, 50},  { 80, 50},  { 90,  50}, { 100, 50}, { 110, 50}, { 130, 50},                         { 165, 50},             { 190, 50}, { 200, 50}, { 210, 50}, 
    { 0, 60},  { 15, 60},  { 25, 60},                                   { 64, 60},                                      { 100, 60}, { 115, 60}, { 130, 60}, { 140, 60}, { 155, 60}, { 165, 60}, { 175, 60}, { 195, 60},             { 210, 60}, { 224, 55}
}, {
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,  1, 
    1,      1,  1,  1,  1,  1,  1,  1,  1,  1,  1,      1,  1,  1,              
    1,  1,  1,          1,              1,  1,  1,  1,  1,  1,  1,      
    1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1 
} };

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    User_Led_Show();

    return false;
}
/*********************************************************/

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
}
/*********************************************************/

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
