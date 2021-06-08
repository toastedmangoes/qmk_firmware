USER_NAME := waffleus
MCU = STM32F303
CTPC = yes
DEBUG_MATRIX_SCAN_RATE_ENABLE = no #Outputs matrix scan rate in QMK Toolbox
SERIAL_DRIVER = usart
WS2812_DRIVER = pwm #needs patch - see https://github.com/qmk/qmk_firmware/pull/11864
VIA_ENABLE = yes
OLED_DRIVER_ENABLE = yes
WPM_ENABLE = yes
AUDIO_ENABLE = no
EXTRAKEY_ENABLE = yes
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
BOOTMAGIC_ENABLE = lite
SPLIT_KEYBOARD = yes
RGBLIGHT_ENABLE = yes
NKRO_ENABLE = yes
ENCODER_ENABLE = no
