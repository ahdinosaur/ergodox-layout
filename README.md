# qmk-keymap

My personal ergonomic split keyboard layouts.

After using my Erogdox's on the same config for almost a decade, not once using layers, hold-keys, combos, or anything fancy, I'm going to experiment with a 3x5 keyboard layout to maybe learn something new.

Built as a [QMK External Userspace](https://docs.qmk.fm/newbs_external_userspace) repo on top of [QMK firmware](https://qmk.fm).

## Layout

See [`keyboards/ergodox_ez/keymaps/dinosaur/keymap.c`](./keyboards/ergodox_ez/keymaps/dinosaur/keymap.c) for the layer mappings.

## Keyboards

- [Ergodox EZ](https://www.zsa.io/ergodox/)

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

## CI

Every push and pull request validates the firmware builds.

Pushing a git tag runs the publish workflow to attach the `.hex` to a GitHub release named after the tag.

See [`.github/workflows/build.yml`](./.github/workflows/build.yml).

Cut a release with:

```sh
git tag v1.0
git push origin v1.0
```
