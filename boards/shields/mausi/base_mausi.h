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
  macros {
  macro_sch:
    macro_sch {
      label = "Macro_sch";
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <&macro_tap &kp S &macro_release &kp RSHIFT &macro_tap &kp C &kp H>;
    };
  macro_ion:
    macro_ion {
      label = "Macro_ion";
      compatible = "zmk,behavior-macro";
      #binding-cells = <0>;
      bindings = <&macro_tap &kp I &macro_release &kp RSHIFT &macro_tap &kp O &kp N>;
    };
  };
};

#define COMBO(NAME, BINDINGS, KEYPOS) \
  combo_##NAME {                      \
    timeout-ms = <20>;                \
    bindings = <BINDINGS>;            \
    key-positions = <KEYPOS>;         \
  };

/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        COMBO(q, &kp Q, 2 3)
        COMBO(z, &kp DE_Z, 20 21)
        COMBO(v, &kp V, 1 2)
        COMBO(b, &kp B, 12 3)
        COMBO(k, &kp K, 12 13)
        COMBO(x, &kp X, 16 17)
        COMBO(j, &kp J, 6 17)
        COMBO(sch, &macro_sch, 11 13)
        COMBO(ion, &macro_ion, 9 16 18)
        COMBO(_sz, &kp DE_SZ, 28 11)
        COMBO(_ue, &kp DE_UE, 28 8)
        COMBO(_ae, &kp DE_AE, 28 17)
        COMBO(_oe, &kp DE_OE, 28 19)
        COMBO(ent, &kp ENTER, 23 24)
        COMBO(esc, &kp ESC, 23 24)
        COMBO(slash, &kp DE_SLASH, 24 25)
/* caps */
        COMBO(capsword, &caps_word, 13 16)
        COMBO(capslock, &kp CAPSLOCK, 0 9)
/* deletion */
        COMBO(bspc, &kp BSPC, 6 7)
        COMBO(del, &kp DEL, 7 8)
        COMBO(bspcword, &kp LC(BSPC), 6 8)

    };
};
/ {
    combos {
        compatible = "zmk,combos";
/* caps */
        /* Umlaute */
        /* deletion */
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
