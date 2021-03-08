#pragma once
#include"POS.h"
struct UNKO {
    struct POS pos;
    float r = 0, g = 0, b = 0;
    static int img;
    static int grabIdx;
};
void createUnko(struct UNKO* unko);
void dragUnko(struct UNKO* unko);
void moveUnko(struct POS* startPos, struct POS& endPos, const struct VEC& vec);
void drawUnko(struct UNKO* unko);