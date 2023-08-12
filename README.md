# Jeff Gaddis's 5x6 Dactyl Manuform Keymap
To be inserted in ~/qmk_firmware/keyboards/handwired/dactyl_manuform/5x6/keymaps/jg-combos

The full combo list is saved here and you can add more to use like a steno keyboard if you compile for a RP2040 with enough space: https://github.com/jeffgaddis/QMK_Combo_Generator

## Keymap Features
This Dactyl Manuform keymap uses Colemack-DH and emphasizes single key press actions instead of holding down keys. A QWERTY layer is also available (good for sharing the keyboard with other people).

It also uses combos to increase typing effeciency. It is convenient to have a thumb key just for combos so I have moved F2 to the top left position since it should not interfere with anything when typing. I previously used backspace to complete combos instead of F2 but this can cause bad inputs when you backspace quickly after making a mistake. It does not seem to be possible to use a LT() key with a key that is used for combos but if there is a way then the _NUM layer could be added with F2. I plan to siginficantly increase the amount of combos available in the future. I think using is combos like this is probably better than learning to use a steno keyboard for most people.

## Other Recommendations
I use this with a Super16 macro pad with 2 rotary encoders. This allows some keys to be more accessable and removes the need to switch layers so frequently.

## Referanced work
- I used Preconditions keymap for a over 1 year and took ideas like combos and Caps Word from it. I decided that I do not like homerow mods due to accidental inputs and because switching to one shot mods removes the need to hold down keys which can cause RSI.
  -  https://github.com/precondition/dactyl-manuform-keymap
- I regularly referance http://xahlee.info/ to decide what the most effecient/least effort layouts and techniques are.
