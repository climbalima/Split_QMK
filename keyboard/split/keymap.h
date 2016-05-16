#ifndef KEYMAP_H
#define KEYMAP_H

/* #define SHIFT(key) ACTION_MODS_KEY(MOD_LSFT, key) */
/* #define CTRL(key)  ACTION_MODS_KEY(MOD_LCTL, key) */
/* #define ALT(key)   ACTION_MODS_KEY(MOD_LALT, key) */
/* #define GUI(key)   ACTION_MODS_KEY(MOD_LGUI, key) */

#define SHIFT(key) ACTION(ACT_MODS, (MOD_LSFT << 8) | (key))
#define CTRL(key) ACTION(ACT_MODS, (MOD_LCTL << 8) | (key))
#define ALT(key) ACTION(ACT_MODS, (MOD_LALT << 8) | (key))
#define GUI(key) ACTION(ACT_MODS, (MOD_LGUI << 8) | (key))


#define KEYMAP( \
    K00, K01, K02, K03, K04, K05, \
    K10, K11, K12, K13, K14, K15, \
    K20, K21, K22, K23, K24, K25, \
    K30, K31, K32, K33, K34, K35, \
\
    K40, K41, K42, K43, K44, K45, \
    K50, K51, K52, K53, K54, K55, \
    K60, K61, K62, K63, K64, K65, \
    K70, K71, K72, K73, K74, K75  \
) { \
    { K00, K01, K02, K03, K04, K05 }, \
    { K10, K11, K12, K13, K14, K15 }, \
    { K20, K21, K22, K23, K24, K25 }, \
    { K30, K31, K32, K33, K34, K35 }, \
\
    { K40, K41, K42, K43, K44, K45 }, \
    { K50, K51, K52, K53, K54, K55 }, \
    { K60, K61, K62, K63, K64, K65 }, \
    { K70, K71, K72, K73, K74, K75 }  \
}

#endif
