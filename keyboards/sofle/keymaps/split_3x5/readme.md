# Sofle split_3x5 with GAME

Six layers: QWERTY, GAME, LOWER, RAISE, NUMERIC, ADJUST.
Hold LOWER + RAISE from either base to open ADJUST. Its first working row
starts with EE_CLR, QK_BOOT, QWERTY, GAME. Mode selection is RAM-only;
a restart returns to the saved default (normally QWERTY).

GAME uses the original custom gaming letters and outer columns:

    Grave 1 2 3 4 5 | 6 7 8 9 0 ]
    Esc   T Q W E R | Y U I O P [
    Tab   G A S D F | H J K L ; '
    Shift B Z X C V | N M , . / Shift
    Ctrl Alt NUMERIC LOWER Space | Enter RAISE LGUI RAlt RCtrl

GAME letters and modifiers have no tap-hold. Layer keys are momentary.
Encoder buttons remain disabled. Overlay thumb keys are transparent so
each base keeps its own modifiers and layer access in either press order.
Current QWERTY mappings, including its function row and outer thumbs, are retained.

QWERTY tap/hold (200 ms, tap-preferred): Esc/Grave, [/], Z/Ctrl,
X/Alt, C/GUI, ./Alt, //Ctrl. Quick-tap repeating is disabled.
The arrow macro retains SEND_STRING_DELAY("->", 10).

ADJUST retains media/brightness, EE_CLR and QK_BOOT, without Ctrl/GUI toggle.
EE_CLR resets saved settings; QK_BOOT enters the bootloader.
Previously saved EEPROM settings are not automatically cleared.

GAME encoder rotation matches QWERTY (scroll/volume). LOWER has horizontal
scroll/track selection; other layers fall through. OLED support is disabled.
MASTER_RIGHT and CONVERT_TO=rp2040_ce are retained.

Build in your QMK environment:

    qmk compile -kb sofle -km split_3x5 -j 8 -e CONVERT_TO=rp2040_ce

Hardware checks: switch both ways through ADJUST; try LOWER/RAISE in both
press and release orders from both bases; check NUMERIC, modifiers, and
release without stuck keys. Firmware compilation and hardware checks are
left to the user. The separate ZMK repository and custom keymap are unchanged.
