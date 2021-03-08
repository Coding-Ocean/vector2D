#pragma once
struct VEC {
    //ベクトル
    float x = 0, y = 0;
    //大きさ
    float mag = 0;
    //正規化(normalized)ベクトル
    float nx = 0, ny = 0;
};
void createVector(struct VEC* vec, const struct POS& startPos, const struct POS& endPos);
void drawVector(const struct POS& startPos, const struct VEC& vec);
void drawVectorInfo(struct VEC& vec);