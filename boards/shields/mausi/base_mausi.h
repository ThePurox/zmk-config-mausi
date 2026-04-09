#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>
#include "keys_de.h"

#define APT 0
#define NAV 1
#define NUM 2
#define SYM 3
#define MED 4
#define DE 4

#define QUICK_TAP_TIME 200

// &lt {
//     quick_tap_ms = <170>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};


/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        combo_q {
            timeout-ms = <40>;
            key-positions = <2 3>;
            bindings = <&kp Q>;
            layers = <APT>;
        };
        combo_z {
            timeout-ms = <40>;
            key-positions = <20 21>;
            bindings = <&kp DE_Z>;
        };
        combo_v {
            timeout-ms = <40>;
            key-positions = <1 2>;
            bindings = <&kp V>;
            layers = <APT>;
        };
        combo_b {
            timeout-ms = <40>;
            key-positions = <12 3>;
            bindings = <&kp B>;
            layers = <APT>;
        };
        combo_j {
          timeout-ms = <40>;
          key-positions = <6 17>;
          bindings = <&kp J>;
          layers = <APT>;
        };
        combo_k {
          timeout-ms = <40>;
          key-positions = <12 13>;
          bindings = <&kp K>;
          layers = <APT>;
        };
        combo_x {
          timeout-ms = <40>;
          key-positions = <16 17>;
          bindings = <&kp X>;
          layers = <APT>;
        };
        combo_slash {
            timeout-ms = <40>;
            key-positions = <24 25>;
            bindings = <&kp SLASH>;
        };
        combo_ent {
            timeout-ms = <40>;
            key-positions = <23 24>;
            bindings = <&kp ENTER>;
        };
/* caps */
        combo_caps-word {
            timeout-ms = <40>;
            key-positions = <13 16>;
            bindings = <&caps_word>;
        };
        combo_capslock {
            timeout-ms = <40>;
            key-positions = <0 9>;
            bindings = <&kp CAPSLOCK>;
        };
        /* Umlaute */
        combo_ue {
          timeout-ms = <20>;
          key-positions = <8 28>;
          bindings = <&kp DE_UE>;
        };
        combo_oe {
          timeout-ms = <20>;
          key-positions = <19 28>;
          bindings = <&kp DE_OE>;
        };
        combo_ae {
          timeout-ms = <20>;
          key-positions = <17 28>;
          bindings = <&kp DE_AE>;
        };
        combo_sz {
          timeout-ms = <20>;
          key-positions = <11 26>;
          bindings = <&kp DE_SZ>;
        };
        /* deletion */
        combo_bspc {
          timeout-ms = <40>;
          key-positions = <7 6>;
            bindings = <&kp BSPC>;
        };
        combo_del {
            timeout-ms = <40>;
            key-positions = <8 7>;
            bindings = <&kp DEL>;
        };
        combo_delword {
            timeout-ms = <40>;
            key-positions = <6 8>;
            bindings = <&kp LC(BSPC)>;
        };
/*F keys*/
        combo_F1 {
          timeout-ms = <40>;
          key-positions = <0 1>;
          layers = <NUM>;
          bindings = <&kp F1>;
        };
        combo_F9 {
          timeout-ms = <40>;
          key-positions = <18 19>;
          layers = <NUM>;
          bindings = <&kp F9>;
        };
    };
};


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <5 6 7 8 9 15 16 17 18 19 23 24 25 26 27 28 29>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 4 10 11 12 13 14 20 21 22 26 27 28 29>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29>;
        };

    };
};
