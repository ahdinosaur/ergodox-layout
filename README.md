# ergodox-layout

My personal [Ergodox EZ](https://www.zsa.io/ergodox/) keyboard layout, built on
[QMK firmware](https://qmk.fm).

See [`keymap.c`](./keymap.c) for the layer mappings.

## Setup

Install the [QMK CLI](https://docs.qmk.fm/cli):

```sh
brew install qmk/qmk/qmk        # macOS
pipx install qmk                # Linux / macOS
```

Then clone the QMK firmware and symlink this keymap into it:

```sh
make setup
```

This puts the firmware tree at `~/qmk_firmware` (override with `QMK_HOME=...`)
and links this directory into
`~/qmk_firmware/keyboards/ergodox_ez/keymaps/dinosaur`.

## Build

```sh
make build
```

The compiled firmware lands in `~/qmk_firmware/` as
`ergodox_ez_base_dinosaur.hex`.

## Flash

Put the keyboard into bootloader mode (press the reset button on the back of
the right half), then:

```sh
make flash
```

GUI alternatives: [Wally](https://www.zsa.io/wally) or
[QMK Toolbox](https://github.com/qmk/qmk_toolbox).

## CI

Every push builds the firmware on GitHub Actions and uploads the `.hex` as a
workflow artifact — see [`.github/workflows/build.yml`](./.github/workflows/build.yml).
