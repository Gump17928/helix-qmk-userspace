#pragma once

// Turn the underglow off when the host goes to sleep.
#define RGBLIGHT_SLEEP

// VIA reserves EEPROM for a fixed number of remappable layers (default 4).
// We ship 5 (_BASE, _LOWER, _RAISE, _ADJUST, _GAMING), so raise the cap.
#define DYNAMIC_KEYMAP_LAYER_COUNT 4

// Sync RGB mode / hue / sat / val / speed from master to slave over TRRS.
#define RGBLIGHT_SPLIT