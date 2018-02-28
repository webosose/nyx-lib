// Copyright (c) 2010-2018 LG Electronics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// SPDX-License-Identifier: Apache-2.0

/**
 * @file nyx_led_controller_common.h
 *
 */


#ifndef _NYX_LED_CONTROLLER_COMMON_H_
#define _NYX_LED_CONTROLLER_COMMON_H_

#include <nyx/common/nyx_led_controller_core_configuration_common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
* @defgroup nyx_led_controller_public LED Controller
* @ingroup nyx_public
* @{
*/

/**
 * Masks that define each type or group of LED
 */
typedef enum
{
	NYX_LED_CONTROLLER_NONE_LED             = 0,
	NYX_LED_CONTROLLER_LEFT_LED             = 0x01,
	NYX_LED_CONTROLLER_CENTER_LED           = 0x02,
	NYX_LED_CONTROLLER_RIGHT_LED            = 0x04,
	NYX_LED_CONTROLLER_KEYPAD               = 0x08,
	NYX_LED_CONTROLLER_LCD                  = 0x10,
	NYX_LED_CONTROLLER_CORE_LEDS            =
	    NYX_LED_CONTROLLER_LEFT_LED | NYX_LED_CONTROLLER_CENTER_LED |
	    NYX_LED_CONTROLLER_RIGHT_LED,
	NYX_LED_CONTROLLER_BACKLIGHT_LEDS =
	    NYX_LED_CONTROLLER_KEYPAD | NYX_LED_CONTROLLER_LCD,
	NYX_LED_CONTROLLER_ALL_LEDS =
	    NYX_LED_CONTROLLER_LEFT_LED | NYX_LED_CONTROLLER_CENTER_LED |
	    NYX_LED_CONTROLLER_RIGHT_LED |
	    NYX_LED_CONTROLLER_KEYPAD | NYX_LED_CONTROLLER_LCD,
}
nyx_led_controller_led_t;



typedef struct
{
	struct
	{
		nyx_led_controller_led_t led;
		nyx_led_controller_effect_type_t effect;
		uint32_t effect_length;
	} required;

	/*
	 * backlight structure is used to provide parameters of the lcd/keypad
	 * backlight control.
	 */
	struct
	{
		int32_t brightness_lcd;
		int32_t brightness_keypad;
		nyx_device_callback_function_t callback;
		void *callback_context;
	} backlight;


	/*
	 * core configuration structure is used to provide parameters of the core led
	 * control.
	 */
	nyx_led_controller_core_configuration_handle_t core_configuration;

} nyx_led_controller_effect_t;

typedef enum
{
	NYX_LED_CONTROLLER_STATE_UNKNOWN,
	NYX_LED_CONTROLLER_STATE_OFF,
	NYX_LED_CONTROLLER_STATE_ON,
} nyx_led_controller_state_t;

typedef enum
{
	NYX_LED_CONTROLLER_ABL_STATE_OFF,
	NYX_LED_CONTROLLER_ABL_STATE_ON,
} nyx_led_controller_abl_state_t;

/*
 * List of the various display modes the led controller module can set
 */

typedef enum
{
	NYX_LED_CONTROLLER_INVERT_COLOUR_OFF,
	NYX_LED_CONTROLLER_INVERT_COLOUR_ON,
	NYX_LED_CONTROLLER_AMBIENT_MODE_OFF,
	NYX_LED_CONTROLLER_AMBIENT_MODE_ON,
	NYX_LED_CONTROLLER_DND_MODE_OFF, /* DND = Do not disturb */
	NYX_LED_CONTROLLER_DND_MODE_ON,
	NYX_LED_CONTROLLER_OUTDOOR_MODE,
} nyx_led_controller_mode_t;


/** @} */
#ifdef __cplusplus
}
#endif

#endif /* _NYX_LED_CONTROLLER_COMMON_H_ */
