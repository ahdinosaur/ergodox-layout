# Build features used by this keymap.
# https://docs.qmk.fm/squeezing_avr

MOUSEKEY_ENABLE   = no    # new design has no mouse keys
EXTRAKEY_ENABLE   = yes   # KC_VOL*, KC_MUTE, KC_MPLY/MSTP/MPRV/MNXT on MED layer

TAP_DANCE_ENABLE  = yes   # Boot / Lc / Lo double-tap activators
LAYER_LOCK_ENABLE = yes   # Lc / Lo use layer_lock_invert()

LTO_ENABLE        = yes

COMMAND_ENABLE    = no
CONSOLE_ENABLE    = no
RGBLIGHT_ENABLE   = no
UNICODE_ENABLE    = no
NKRO_ENABLE       = no

# Default-yes features we don't use — disabling trims AVR flash.
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE   = no
MAGIC_ENABLE       = no
