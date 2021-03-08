#pragma once
struct VEC {
    //�x�N�g��
    float x = 0, y = 0;
    //�傫��
    float mag = 0;
    //���K��(normalized)�x�N�g��
    float nx = 0, ny = 0;
};
void createVector(struct VEC* vec, const struct POS& startPos, const struct POS& endPos);
void drawVector(const struct POS& startPos, const struct VEC& vec);
void drawVectorInfo(struct VEC& vec);