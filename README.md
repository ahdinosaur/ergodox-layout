# ergodox-layout

My personal [Ergodox EZ](https://www.zsa.io/ergodox/) keyboard layout, built as a [QMK External Userspace](https://docs.qmk.fm/newbs_external_userspace) repo on top of [QMK firmware](https://qmk.fm).

See [`keyboards/ergodox_ez/keymaps/dinosaur/keymap.c`](./keyboards/ergodox_ez/keymaps/dinosaur/keymap.c) for the layer mappings.

## Setup

Install the [QMK CLI](https://docs.qmk.fm/cli):

```sh
curl -fsSL https://install.qmk.fm | sh
```

Then run setup:

```sh
make setup
```

## Build

```sh
make build
```

This runs `qmk userspace-compile`, which builds every target listed in `qmk.json`.

The compiled firmware will be a `.hex`.

You can also drive the underlying make target directly:

```sh
make ergodox_ez:dinosaur
```

## Flash

Put the keyboard into bootloader mode (press the reset button on the back of the right half), then:

```sh
make flash
```

GUI alternatives: [Wally](https://www.zsa.io/wally) or [QMK Toolbox](https://github.com/qmk/qmk_toolbox).

## keyboard-helper integration

The firmware in this repo speaks the
[keyboard-helper](https://github.com/ahdinosaur/keyboard-helper) Raw HID
protocol, and this repo doubles as a *keymap-library directory* that the
keyboard-helper app can read.

There are two pieces:

1. **Firmware side** — the C handler is pulled in as a git submodule at
   [`keyboards/ergodox_ez/keymaps/dinosaur/keyboard-helper/`](./keyboards/ergodox_ez/keymaps/dinosaur/keyboard-helper).
   `keymap.c` `#define`s a `KEYBOARD_HELPER_ID` and forwards three QMK
   callbacks to the helper's hooks; `rules.mk` enables `RAW_ENABLE` and
   compiles the helper's `keyboard_helper.c` from inside the submodule.
   Update with `git submodule update --remote`.

2. **Host side** — [`keymaps.toml`](./keymaps.toml) plus the
   [`ergodox-ez-dinosaur.yaml`](./ergodox-ez-dinosaur.yaml) keymap-drawer
   layout. Open the keyboard-helper app, point its "keymaps folder"
   setting at the root of this repo, and the Ergodox card will appear
   on the Start screen.

If you fork this repo for a different keyboard or layout:

- Pick a new `KEYBOARD_HELPER_ID` (ASCII, 1–24 bytes, `[A-Za-z0-9_-]`).
  Update the `#define` in `keymap.c` and the matching table key in
  `keymaps.toml`.
- Replace `ergodox-ez-dinosaur.yaml` with a keymap-drawer YAML for your
  layout (`keymap-drawer parse -c '...' qmk_keymap.c > yours.yaml`).
- See the
  [keyboard-helper QMK template README](./keyboards/ergodox_ez/keymaps/dinosaur/keyboard-helper/firmware/qmk/template/README.md)
  for full submodule install steps, including the `keymap.c` patch
  sketch and the `keyboard_helper_position_from_keypos` override needed
  for split / remapped boards (the ergodox falls into that category;
  without an override, layer indication still works but key
  highlighting will land on the wrong key).

## CI

Every push and pull request runs the official QMK userspace [reusable workflow](https://github.com/qmk/.github/blob/main/.github/workflows/qmk_userspace_build.yml) to validate the firmware builds. Pushing a git tag additionally runs the [publish workflow](https://github.com/qmk/.github/blob/main/.github/workflows/qmk_userspace_publish.yml) to attach the `.hex` to a GitHub Release named after the tag. See [`.github/workflows/build.yml`](./.github/workflows/build.yml).

Cut a release with:

```sh
git tag v1.0
git push origin v1.0
```
