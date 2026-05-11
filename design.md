# Layout design

## Home row mods

We use the home row mods of:

```
(left)
Super Alt Ctrl Shift

(right)
Shift Ctrl Alt Super
```

With the following settings

- [`TAPPING_TERM`](https://docs.qmk.fm/tap_hold#tapping-term): `250`
- [`PERMISSIVE_HOLD`](https://docs.qmk.fm/tap_hold#permissive-hold)
- [`FLOW_TAP_TERM`](https://docs.qmk.fm/tap_hold#flow-tap): `150`
- [`CHORDAL_HOLD`](https://docs.qmk.fm/tap_hold#chordal-hold)
- [`SPECULATIVE_HOLD`](https://docs.qmk.fm/tap_hold#speculative-hold)

## Thumbs

The thumbs are:

(Left: Tertiary, Primary, Secondary order)

```
(left thumbs)
Escape Backspace Delete
```

(Right: Secondary, Primary, Tertiary order)

```
(right thumbs)
Enter Space Tab
```

## Layers

### Thumb mods

We trigger the layers with thumb mods:

```

```

### Number layer

- I like the numpad approach, inspired by Moonlander symbol layer
- Also https://github.com/getreuer/qmk-keymap's number layer

```
(right)
/789-
*456+
%123^

(right thumb)
  .0=
```

Triggered by left primary thumb key.

### Navigation Layer

- Inspired by https://github.com/manna-harbour/miryoku

```
(left)
Redo Paste Copy Cut Undo
CapsLock Left Down Up Right
Insert Home PageDown PageUp End
```

Triggered by right primary thumb key.

TODO: Activate with right-left thumb combo?

### Symbol layer

- I want the brackets to be easy.
- I use Rust, TypeScript, Linux, Markdown, but also want to be flexible.
- I want to re-use placements with exisnig shifted keys
  - I like having `!@#$% ^&` be where it'd be for a number.
  - I like `<>?` where it'd be as shifted `,./`.

```
(left)
!@#$%
*_-="
~/+`'

(right)
^&[]|
:(){}
\→<>?
```

Trigged by either secondary thumb key.

### Fun layer

```
(left)
F12 F7 F8 F9 PrtScn
F11 F4 F5 F6 ScrollLock
F10 F1 F2 F3 PauseBreak
```

Triggered by right tertiary thumb key.

Left thumb keys are the same as base, to allow for auto-repeat.

### Media layer

```
(right)
<blank line>
 Prev VolumeDown VolumeUp Next
 Pause/Play Stop Mute
```

Triggered by left tertiary thumb key.

Right thumb keys are the same as base, to allow for auto-repeat.

## Inspiration

- https://github.com/manna-harbour/miryoku
- getreuer
  - https://getreuer.info/posts/keyboards/symbol-layer/index.html
  - https://github.com/getreuer/qmk-keymap
- precondition:
  - https://precondition.github.io/home-row-mods
  - https://github.com/precondition/dactyl-manuform-keymap
- https://www.reddit.com/r/ErgoMechKeyboards/comments/1q1jo3c/urobs_zmk_timeless_home_row_mods_ported_to_native/
- urob: https://github.com/urob/zmk-config
- Seniply: https://stevep99.github.io/seniply/
- Ben Vallack: https://benvallack.com/notebook/36-key-corne-keyboard-layout/
- Wellum: https://github.com/braindefender/wellum/blob/master/for-36-keys_en.md
- mforman: https://github.com/mforman/zmk-config
- https://keymap-drawer.streamlit.app/
- https://mark.stosberg.com/markstos-corne-3x5-1-keyboard-layout/
- https://keymap-drawer.streamlit.app/?example_yaml=3x5.yaml
