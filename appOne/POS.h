#pragma once
struct POS {
    float x, y;
    POS() {
        x = 0;
        y = 0;
    }
    POS(float x, float y) {
        this->x = x;
        this->y = y;
    }
};