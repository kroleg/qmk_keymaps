BOOTMAGIC_ENABLE = yes
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
CONSOLE_ENABLE = yes         # Console for debug
COMMAND_ENABLE = no
LTO_ENABLE = yes
MOUSEKEY_ENABLE = no
OLED_ENABLE = no
ENCODER_ENABLE = no
# https://docs.qmk.fm/#/feature_caps_word
CAPS_WORD_ENABLE = yes
# because i am using black promicro rp2040 same as https://mechboards.co.uk/products/pro-micro-5v
# and they advise to use rp2040_ce
# see pro-micro-rp2040-pinout.webp
CONVERT_TO=rp2040_ce
