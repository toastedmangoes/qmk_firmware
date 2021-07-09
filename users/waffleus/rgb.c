/* Copyright 2021 @waffle#0007
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "rgb.h"
#ifdef RGBLIGHT_EFFECT_STATIC_GRADIENT
const uint8_t RGBLED_GRADIENT_RANGES[] PROGMEM = {127, 127, 148, 0, 0};
#endif
bool process_record_user_rgblight(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CYAN:
            if (record->event.pressed) {
                rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
                rgblight_sethsv(0, 255, 255);
            }
            break;
    }
    return true;
}

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM my_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 12, HSV_PURPLE} );
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 12, HSV_YELLOW} );
const rgblight_segment_t PROGMEM my_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS( {0, 12, HSV_PINK} );
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_lower_layer,
    my_raise_layer,
    my_adjust_layer
);

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}
#endif

__attribute__ ((weak)) void keyboard_post_init_user(void) {
  rgblight_enable_noeeprom();
  rgblight_sethsv_noeeprom(HSV_CYAN);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}

void keyboard_post_init_rgblight(void) {
#ifdef RGBLIGHT_LAYERS
    rgblight_layers = my_rgb_layers;
#endif
}
