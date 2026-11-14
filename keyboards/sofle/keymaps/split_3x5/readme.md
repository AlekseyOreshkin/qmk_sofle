# Three-row, five-layer Sofle layout

Five layers: QWERTY, LOWER, RAISE, NUMERIC, ADJUST.
Hold LOWER + RAISE for ADJUST. GAME and Ctrl/GUI toggle are removed.

The number row, encoder buttons, and four outer thumb keys are KC_NO on
every layer. The six inner thumbs are NUMERIC, LOWER, Space / Enter, RAISE, GUI.
Transparent keys retain the underlying action.

Tap/hold (200 ms, tap-preferred): Esc/Grave, [/], Z/Ctrl, X/Alt,
C/GUI, ./Alt, and //Ctrl. Quick-tap repeating is disabled so a repeated
press can become a hold. The arrow macro retains SEND_STRING_DELAY("->", 10).

ADJUST: EE_CLR and QK_BOOT at the left of its first working row.
The right half has media, volume and brightness controls.
EE_CLR resets saved QMK settings; QK_BOOT enters the bootloader.
Old EEPROM settings are preserved; use EE_CLR if a previous Ctrl/GUI swap persists.

Encoder rotation preserves custom's base scroll/volume and LOWER
horizontal scroll/track selection. Other layers fall through.
OLED labels follow the five layers.

Build in your QMK environment:

    qmk compile -kb sofle/rev1 -km split_3x5

MASTER_RIGHT and CONVERT_TO=rp2040_ce match the local custom keymap.
This implements the five-layer design agreed in chat. Existing custom
files and the separate ZMK repository are unchanged.
Firmware compilation and hardware verification are left to the user.

Check taps below 200 ms, holds above 200 ms, overlapping key presses,
repeated taps followed by holds, release without stuck keys, both release
orders of LOWER + RAISE, disabled keys, macro, encoders and service keys.
