# Flashing the Cantor

## 1) Install `qmk`

For Mac, you will need Homebrew:

```
brew install qmk/qmk/qmk
```

If this fails, see [this Reddit post](https://www.reddit.com/r/olkb/comments/nh2fk9/guide_installing_qmk_on_m1_macbook/)

For Linux distros, you will need Python/pip:

```
python3 -m pip install --user qmk
```

## 2) Set up `qmk`

```
setup qmk
```

## 3) Clone this repo

See 2 next points to clone directly into `qmk` home folder.

## 4) [OPTIONAL] Set home directory for QMK firmware

```
qmk setup -H /path/to/dir
```

Default is `~/qmk_firmware`

## 5) Copy files into `qmk` home folder

Put files under `keyboards/planck/keymaps/<keymap-name>`

## 6) Compile keymap

```
qmk compile -kb <keyboard-name> -km <keymap-name>
```

This keymap is for the `cantor` keyboard

## 7) Put keyboard in BOOT mode

Press and hold BOOT

Press NRST

Release BOOT

## 8) Flash the keyboard

```
qmk flash -kb <keyboard-name> -km <keymap-name>
```

This keymap is for the `cantor` keyboard

## More info

### Known issues

If you are missing dependencies that cannot be automatically found with Homebrew, add the taps manually and retry:

```
brew tap osx-cross/avr osx-cross/arm
brew install avr-gcc arm-none-eabi-gcc@8
```

Make sure `arm-none-eabi-gcc` is added to your path.

### Links

For all keycodes, see [qmk/qmk_firmware/docs/keycodes](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md)

For full QMK tutorial, see [docs.qmk.fm](https://docs.qmk.fm/)
