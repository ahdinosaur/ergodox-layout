# Build features used by this keymap.
# https://docs.qmk.fm/squeezing_avr

MOUSEKEY_ENABLE   = yes  # MS_*, MS_BTN1/2 on the MDIA layer
EXTRAKEY_ENABLE   = yes  # KC_VOL*, KC_MUTE, KC_MPLY, KC_WBAK on the MDIA layer

LTO_ENABLE        = yes  # link-time optimization, smaller binary on AVR

COMMAND_ENABLE    = no
CONSOLE_ENABLE    = no
TAP_DANCE_ENABLE  = no
RGBLIGHT_ENABLE   = no
UNICODE_ENABLE    = no
NKRO_ENABLE       = no

# keyboard-helper integration (submodule at ./keyboard-helper).
# See https://github.com/ahdinosaur/keyboard-helper for the protocol.
RAW_ENABLE = yes
SRC   += $(KEYMAP_PATH)/keyboard-helper/firmware/qmk/template/keyboard_helper.c
VPATH += $(KEYMAP_PATH)/keyboard-helper/firmware/qmk/template
