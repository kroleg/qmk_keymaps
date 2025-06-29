BOOTMAGIC_ENABLE = yes
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = no
LTO_ENABLE = yes
MOUSEKEY_ENABLE = no
OLED_ENABLE = no
ENCODER_ENABLE = no
COMBO_ENABLE = yes
# https://docs.qmk.fm/#/feature_caps_word
CAPS_WORD_ENABLE = yes
# i use promicro rp2040 same as https://mechboards.co.uk/products/pro-micro-5v (see pro-micro-rp2040-pinout.webp)
# previously it worked with promicro_rp2040 but it's deprecated and replaced by sparkfun_pm2040
# proof https://github.com/qmk/qmk_firmware/blame/177e461d903e6414e6d7b5b80eb36f48b0d68626/platforms/chibios/converters/promicro_to_promicro_rp2040/pre_converter.mk#L5
CONVERT_TO=sparkfun_pm2040
