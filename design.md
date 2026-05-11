# Layout design

A 36-key (3×5 + 3 thumbs per hand) ergonomic split keyboard layout, designed for both the Ergodox EZ (extra outer columns left empty) and the Cheapino (true 3×5+3).

## Conventions

- Layouts are shown as 3 rows × 5 columns per hand, plus 3 thumb keys per hand.
- Each hand reads pinky → inner-index from outer column to inner column.
- `NO` means the key does nothing (`KC_NO`).
  - Every active key is explicit; unspecified positions default to `NO`, not transparent.
- `--` marks the layer's trigger key (held while the layer is active).
- Modifier abbreviations: `Sup` (Super/GUI), `Alt`, `Ctl`, `Sft` (Shift).
- Where a non-base layer shows `Sup` / `Alt` / `Ctl` / `Sft` on the home row, these are **plain modifiers**, not mod-taps. Mod-taps only exist on the base layer.

## Home row mods

GACS order, mirrored across hands:

```
Left:   A = Sup   R = Alt   S = Ctl   T = Sft
Right:  N = Sft   E = Ctl   I = Alt   O = Sup
```

Settings:

- [`TAPPING_TERM`](https://docs.qmk.fm/tap_hold#tapping-term): `250`
- [`PERMISSIVE_HOLD`](https://docs.qmk.fm/tap_hold#permissive-hold)
- [`FLOW_TAP_TERM`](https://docs.qmk.fm/tap_hold#flow-tap): `150`
- [`CHORDAL_HOLD`](https://docs.qmk.fm/tap_hold#chordal-hold)
- [`SPECULATIVE_HOLD`](https://docs.qmk.fm/tap_hold#speculative-hold)

## Thumbs

```
Left thumbs:    Esc    Bsp    Del
                (tertiary, primary, secondary)

Right thumbs:   Ent    Spc    Tab
                (secondary, primary, tertiary)
```

Each thumb is a layer-tap (`LT(layer, kc)`):

```
Left tertiary  (Esc) → Media     Right secondary (Ent) → Symbol
Left primary   (Bsp) → Number    Right primary   (Spc) → Nav
Left secondary (Del) → Symbol    Right tertiary  (Tab) → Fun
```

## Additional features

While any single-hand layer is held, the **trigger-side hand** gets these extras (inspired by Miryoku's "Additional Features"):

- Top row pinky:    `Boot` — activate the bootloader.
- Bottom row index: `Lc`   — lock the current layer.
- Bottom row middle: `Lo`  — lock the opposite-hand layer.

All require **double-tap** to activate (QMK tap-dance), to prevent accidental triggering.

These do **not** apply to the Symbol layer (bilateral, no trigger-side hand).

## Layers

### Base (Colemak)

```
  Q      W      F      P      G          J      L      U      Y      ;
  A      R      S      T      D          H      N      E      I      O
  Z      X      C      V      B          K      M      ,      .      /

                Esc    Bsp    Del        Ent    Spc    Tab
```

Home-row alphas are mod-taps. Thumbs are layer-taps. See sections above for assignments.

### Number layer

Hold left primary (Bsp). Active hand: right.

```
  Boot   NO     NO     NO     NO         /      7      8      9      -
  Sup    Alt    Ctl    Sft    NO         *      4      5      6      +
  NO     NO     Lo     Lc     NO         %      1      2      3      ^

                NO     --     NO         .      0      =
```

- Right hand: numpad style, inspired by the Moonlander symbol layer and getreuer's number layer.
- Right thumbs continue the numpad (`. 0 =`).
- `Lo` = lock Nav (opposite of Num).

### Navigation layer

Hold right primary (Spc). Active hand: left.

```
  Redo   Past   Copy   Cut    Undo       NO     NO     NO     NO     Boot
  Caps   Left   Down   Up     Right      NO     Sft    Ctl    Alt    Sup
  Ins    Home   PgDn   PgUp   End        NO     Lc     Lo     NO     NO

                Esc    Bsp    Del        NO     --     NO
```

- Inspired by Miryoku.
- Left thumbs stay as base (Esc/Bsp/Del) so Backspace and friends remain available while navigating.
- `Lo` = lock Number (opposite of Nav).

### Symbol layer

Hold left secondary (Del) **or** right secondary (Ent). Active: both hands.

```
  !      @      #      $      %          ^      &      [      ]      |
  *      _      -      =      "          :      (      )      {      }
  ~      /      +      `      '          \      →      <      >      ?

                NO     NO     NO         NO     NO     NO
```

- All thumbs are `NO` (since either secondary can trigger, both hands' thumbs are trigger-adjacent).
- No additional features (no clear trigger-side hand).
- No home-row mods (positions taken by symbols).
- Brackets pair on adjacent positions: `[]` `{}` `()`.
- Shifted-number positions preserved: `! @ # $ % ^ &` in their natural spots.
- `< > ?` kept where they are as shifted `, . /` on Colemak.
- `~ /` adjacent (left bottom) for shell paths.
- `( )` adjacent on right index/middle for autocomplete-friendly typing.
- `→` (right bottom col 2) is a TBD placeholder slot.

### Fun layer

Hold right tertiary (Tab). Active hand: left.

```
  F12    F7     F8     F9     PrSc       NO     NO     NO     NO     Boot
  F11    F4     F5     F6     ScLk       NO     Sft    Ctl    Alt    Sup
  F10    F1     F2     F3     Paus       NO     Lc     Lo     NO     NO

                Esc    Bsp    Del        NO     --     NO
```

- Left thumbs stay as base (Esc/Bsp/Del) to allow auto-repeat / use while on Fun.
- `Lo` = lock Media (opposite of Fun).

### Media layer

Hold left tertiary (Esc). Active hand: right.

```
  Boot   NO     NO     NO     NO         NO     NO     NO     NO     NO
  Sup    Alt    Ctl    Sft    NO         Prev   VolDn  VolUp  Next   NO
  NO     NO     Lo     Lc     NO         Play   Stop   Mute   NO     NO

                NO     --     NO         Ent    Spc    Tab
```

- Right thumbs stay as base (Ent/Spc/Tab) to allow auto-repeat / use while on Media.
- Top row right hand intentionally empty for now.
- `Lo` = lock Fun (opposite of Media).

## Inspiration

- [manna-harbour/miryoku](https://github.com/manna-harbour/miryoku)
- getreuer
  - [Designing a symbol layer](https://getreuer.info/posts/keyboards/symbol-layer/index.html)
  - [getreuer/qmk-keymap](https://github.com/getreuer/qmk-keymap)
- precondition
  - [A guide to home row mods](https://precondition.github.io/home-row-mods)
  - [precondition/dactyl-manuform-keymap](https://github.com/precondition/dactyl-manuform-keymap)
- [urob's ZMK "timeless" home row mods, ported to native QMK (reddit)](https://www.reddit.com/r/ErgoMechKeyboards/comments/1q1jo3c/urobs_zmk_timeless_home_row_mods_ported_to_native/)
- [urob/zmk-config](https://github.com/urob/zmk-config)
- [Seniply](https://stevep99.github.io/seniply/)
- [Ben Vallack — 36-key Corne layout](https://benvallack.com/notebook/36-key-corne-keyboard-layout/)
- [Wellum — for 36 keys (en)](https://github.com/braindefender/wellum/blob/master/for-36-keys_en.md)
- [mforman/zmk-config](https://github.com/mforman/zmk-config)
- [keymap-drawer (Streamlit)](https://keymap-drawer.streamlit.app/)
- [markstos — Corne 3×5+1 layout](https://mark.stosberg.com/markstos-corne-3x5-1-keyboard-layout/)
- [keymap-drawer 3x5 example](https://keymap-drawer.streamlit.app/?example_yaml=3x5.yaml)
- [sunaku — bilateral combinations / home row mods](https://sunaku.github.io/home-row-mods.html)

## Maybe?

Ideas to consider after the base design has been used for a while:

- **Two-layers-held "adjust" layer** — e.g., simultaneous Num + Nav unlocks a tri-state layer for system bits (EE_CLR, RGB controls, etc.).
- **Mouse layer** — cursor, scroll, buttons. Possibly urob's "smart mouse" pattern (auto-activates from Nav, auto-deactivates on non-mouse input).
- **Caps Word** — auto-shift the next word, releases on space/punctuation. Great for `SCREAMING_SNAKE_CASE`.
- **Repeat Key / Magic Key** — re-fires the previous key; useful for repeated symbols (`==`, `..`, `->`) and to relieve pinky strain.
- **Autocorrect** — Getreuer's typo-fixing module (now in QMK core).
- **Numword** — sticky Number layer that auto-exits on non-numeric input.
- **Combos** — multi-key chords; possible alternative trigger for the Nav layer (right + left primary thumbs).
- **Swapper** — tri-state alt-tab window switching.
- **Swap `;` and `'`** — make `'` the right-pinky home position; `;` moves to the symbol layer or top row.
- **Move home-row mods to bottom row** — less mistrigger risk, but bottom row is more awkward to reach.
- **Bilateral combinations** for layer triggers — sunaku's approach where layer holds require opposite-hand activation.
