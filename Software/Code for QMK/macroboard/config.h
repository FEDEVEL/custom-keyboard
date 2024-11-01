#pragma once


/* Double tap reset button to enter bootloader */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U

#define ENCODER_MAP_KEY_DELAY 10

//#define WS2812_DI_PIN GP24
//#define RGBLED_NUM 4
#define WS2812_TIMING 1600
#define WS2812_T1H 700
#define WS2812_T0H 300
#define WS2812_TRST_US 300
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB
//#define NOP_FUDGE 0.4

//#define SOLENOID_PIN GP23

/*#ifdef BACKLIGHT_ENABLE
#   define BACKLIGHT_PWM_DRIVER PWMD5
#   define BACKLIGHT_PWM_CHANNEL RP2040_PWM_CHANNEL_A
#endif*/

#define LED_NUM_LOCK_PIN GP26
#define LED_CAPS_LOCK_PIN GP27
#define LED_SCROLL_LOCK_PIN GP28
#define LED_PIN_ON_STATE 0