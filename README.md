# ergodox-layout

personal ergodox layout

see the [key mapping](./keymap.c)

## scripts

### build

uses `keymap.c` to build `ergodox_ez.hex` with help from [`potz/docker-ergodox-ez-compiler`](https://github.com/potz/docker-ergodox-ez-compiler/).

### flash

downloads [`teensy` for Linux](https://www.pjrc.com/teensy/loader_linux.html) if not already, runs `teensy` that can be used to flash ergodox firmware.
