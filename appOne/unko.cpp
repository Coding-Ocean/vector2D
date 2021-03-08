#include"libOne.h"
#include"vector2D.h"
#include"unko.h"

int UNKO::img = 0;
int UNKO::grabIdx = 0;

void createUnko(struct UNKO* unko) {
    unko->img = loadImage("assets\\unkoWhite.png");
    unko->grabIdx = -1;
    unko[0].pos.x = -4;
    unko[0].pos.y = -4;
    unko[0].r = 0;
    unko[0].g = 0;
    unko[0].b = 255;
    unko[1].pos.x = -1;
    unko[1].pos.y = -1;
    unko[1].r = 255;
    unko[1].g = 0;
    unko[1].b = 255;
}
void dragUnko(struct UNKO* unko) {
    //‚Â‚©‚Þ
    if (isTrigger(MOUSE_LBUTTON)) {
        float x, y, dist, minDist = 99999;
        unko->grabIdx = -1;
        for (int i = 0; i < 2; i++) {
            x = unko[i].pos.x - mathMouseX;
            y = unko[i].pos.y - mathMouseY;
            dist = sqrt(x * x + y * y);
            if (dist < minDist) {
                minDist = dist;
                unko->grabIdx = i;
            }
        }
        if (minDist > 0.5f) {
            unko->grabIdx = -1;
        }
    }
    //ƒhƒ‰ƒbƒO
    if (isPress(MOUSE_LBUTTON)) {
        if (unko->grabIdx >= 0) {
            unko[unko->grabIdx].pos.x = (int)mathMouseX;
            unko[unko->grabIdx].pos.y = (int)mathMouseY;
        }
    }
}
void moveUnko(struct POS* startPos, struct POS& endPos, const struct VEC& vec) {
    if (isPress(KEY_SPACE)) {
        if (vec.mag > 0.05f) {
            startPos->x += vec.nx * 0.05f;
            startPos->y += vec.ny * 0.05f;
        }
        else {
            *startPos = endPos;
        }
    }
}
void drawUnko(struct UNKO* unko) {
    rectMode(CENTER);
    for (int i = 0; i < 2; i++) {
        imageColor(unko[i].r, unko[i].g, unko[i].b);
        mathImage(unko->img, unko[i].pos.x, unko[i].pos.y);
    }
}
