# My QMK keymaps

This is a fork of qmk/qmk_userspace i use to compile keymaps without having to fork the main QMK repository.

## Howto build in devcontainer

1. start devcontainer using vscode
1. run setup `./.devcontainer/setup.sh`. Maybe `qmk setup` will work instead
1. Add a new keymap for your board using `qmk new-keymap` or copy one from you qmk fork (ex: `keyboards/crkbd/keymaps/<your keymap name>`).
1. run `qmk compile -kb crkbd -km kroleg`
