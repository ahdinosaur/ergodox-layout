# ergodox-layout

My personal [Ergodox EZ](https://www.zsa.io/ergodox/) keyboard layout, built as
a [QMK External Userspace](https://docs.qmk.fm/newbs_external_userspace) repo
on top of [QMK firmware](https://qmk.fm).

See [`keyboards/ergodox_ez/keymaps/dinosaur/keymap.c`](./keyboards/ergodox_ez/keymaps/dinosaur/keymap.c)
for the layer mappings.

## Setup

Install the [QMK CLI](https://docs.qmk.fm/cli):

```sh
brew install qmk/qmk/qmk        # macOS
pipx install qmk                # Linux / macOS
```

Then clone QMK firmware and register this repo as the userspace overlay:

```sh
make setup
```

This runs `qmk setup` (clones `qmk_firmware` to `~/qmk_firmware` if absent) and
sets `user.overlay_dir` to point at this directory. After that, QMK reads build
targets from [`qmk.json`](./qmk.json) and finds the keymap under
`keyboards/ergodox_ez/keymaps/dinosaur/`.

## Build

```sh
make build
```

This runs `qmk userspace-compile`, which builds every target listed in
`qmk.json`. The compiled firmware lands at the qmk_firmware root as
`ergodox_ez_base_dinosaur.hex`.

You can also drive the underlying make target directly:

```sh
make ergodox_ez:dinosaur
```

## Flash

Put the keyboard into bootloader mode (press the reset button on the back of
the right half), then:

```sh
make flash
```

GUI alternatives: [Wally](https://www.zsa.io/wally) or
[QMK Toolbox](https://github.com/qmk/qmk_toolbox).

## CI

Every push and pull request runs the official QMK userspace
[reusable workflow](https://github.com/qmk/.github/blob/main/.github/workflows/qmk_userspace_build.yml)
to validate the firmware builds. Pushing a git tag additionally runs the
[publish workflow](https://github.com/qmk/.github/blob/main/.github/workflows/qmk_userspace_publish.yml)
to attach the `.hex` to a GitHub Release named after the tag. See
[`.github/workflows/build.yml`](./.github/workflows/build.yml).

Cut a release with:

```sh
git tag v1.0
git push origin v1.0
```
