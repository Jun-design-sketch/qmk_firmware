
# Ploopyco Madromys Trackball

It's a DIY, QMK-powered trackball!

* Keyboard Maintainer: [PloopyCo](https://github.com/ploopyco)
* Hardware Supported: RP2040
* Hardware Availability: [Store](https://ploopy.co), [GitHub](https://github.com/ploopyco)

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb ploopyco/madromys -km default

# Building Firmware

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

# Triggering the Bootloader

[Do you see those two golden holes in the board](https://ploopy.co/wp-content/uploads/2023/11/boot.jpg)? Those are called **vias**. They act exactly like a switch does. Right now, that switch is OFF. However, if you take a paperclip or a pair of metal tweezers and touch those two vias, the two vias will form an electrical connection. Effectively, that switch turns ON.

Go ahead and connect the two vias, and then (while the vias are connected) plug in the Madromys board into your computer.

The computer should recognise that a mass storage device was just plugged in. Once this is done, you should be able to drag and drop files onto the Madromys board, as if the board was a USB drive. Feel free to remove the tweezers or paperclip at this point.

If you want to upload a new firmware file (a ".uf2" file, like "madromys_awesome_version.uf2" or something), just drag it into the folder, and it'll automatically install on the Madromys board and restart itself, in normal operating mode. You're done!

**TIP**: If your firmware is in some kind of strange state and uploading new firmware isn't fixing it, try uploading [a flash nuke](https://learn.adafruit.com/getting-started-with-raspberry-pi-pico-circuitpython/circuitpython#flash-resetting-uf2-3083182) to the Madromys board before flashing the new firmware. It wipes the memory of the Madromys board completely clean, which can help clear a few types of errors.

# Customizing your Ploopy Madromys

You can find customziation options [here](../readme.md).

# 自分用のメモ

https://ploopyco.github.io/adept-trackball/appendices/programming/

qmk使用にあたり、qmkをインストールせねばならない。
python3 -m pip install --user qmk
インストール後、qmkの位置を確認する。
find ~/Library/Python -type f -name qmk
find ~/.local/bin -type f -name qmk
コマンド使用できるよう環境変数に登録する。Pythonのバージョンなどを環境にあわせ適宜変更。
echo 'export PATH="$HOME/Library/Python/3.9/bin:$PATH"' >> ~/.zshrc
記載完了を確認する。
cat ~/.zshrc
現在のシェルに適用する。
source ~/.zshrc
QMKの稼働を確認する。
qmk --version

qmk configし、現在の設定を確認でき qmk doctorし、診断できる。
稼働時のホームディレクトリを設定する。
qmk setup -H ~/projects/adept-trackball
ホームディレクトリを基準に、-kb -kmのパスパラメータを入れる。
qmk compile -kb ploopy/adept -km mykeymap

keymapはCで書かれるが、なぜqmkはpython基盤でkeymapはCなのか？
マイコン（MCU）上で動くC基盤のTMKから、QMKが分岐。
QMK Firmware > C：MCU上で動く, USB HID処理・キー入力処理
QMK CLI > Python：ビルド・書き込みツール

