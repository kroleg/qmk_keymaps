#!/usr/bin/env bash

set -eEuo pipefail

python3 -m pip install qmk
python3 -m pip install --upgrade milc

git config --global --add safe.directory /workspaces/qmk_userspace
git submodule update --init --recursive

[ -d /workspaces/qmk_firmware ] || git clone https://github.com/qmk/qmk_firmware.git /workspaces/qmk_firmware
git config --global --add safe.directory /workspaces/qmk_firmware

qmk config user.qmk_home=/workspaces/qmk_firmware
qmk config user.overlay_dir=/workspaces/qmk_userspace

qmk git-submodule
