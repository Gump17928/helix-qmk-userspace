# helix-qmk-userspace

Personal QMK userspace for a Helix split keyboard, based on
[TNKSoftware/helix_remix](https://github.com/TNKSoftware/helix_remix)
(MIT). The original readme is preserved as
[UPSTREAM_README.md](UPSTREAM_README.md).

## Layout

- `keyboards/helix_remix/` — full keyboard definition copied from upstream.
- `keyboards/helix_remix/keymaps/gump/` — my keymap (currently a copy of
  upstream `default`; will diverge over time).
- `tools/` — upstream Python helpers (`hex2hsv.py`, `img2hex.py`).
- `.github/workflows/build.yml` — GitHub Actions CI that builds via the
  official `qmk/qmk_userspace_build.yml` workflow and publishes the
  resulting `.hex` as a downloadable artifact.

## Build target

```json
["helix_remix", "gump"]
```

Locally:

```sh
qmk userspace-add -kb helix_remix -km gump
qmk userspace-compile
```

## Flash

1. Download the `Firmware` artifact from the latest green run on the
   [Actions tab](../../actions).
2. Extract the `.hex` file.
3. Flash both halves with [QMK Toolbox](https://qmk.fm/toolbox/)
   (bootloader: **caterina**, tap the pro-micro reset button on each half).

## License

MIT — see [LICENSE](LICENSE). Attribution to Tanaka Yusuke / TNKSoftware.
