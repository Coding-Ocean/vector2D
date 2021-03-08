#include"libOne.h"
#include"POS.h"
#include"vector2D.h"
//ベクトル
void createVector(VEC* vec, const POS& startPos, const POS& endPos) {
    //ベクトルを求める
    vec->x = endPos.x - startPos.x;
    vec->y = endPos.y - startPos.y;
    //ベクトルの大きさを求める
    vec->mag = sqrt(vec->x * vec->x + vec->y * vec->y);
    //正規化ベクトルを求める
    if (vec->mag > 0) {
        vec->nx = vec->x / vec->mag;
        vec->ny = vec->y / vec->mag;
    }
    else {
        vec->nx = 0;
        vec->ny = 0;
    }
}
void drawVector(const POS& startPos, const VEC& vec) {
    if (vec.mag > 0) {
        strokeWeight(10);
        stroke(0);
        mathArrow(startPos.x, startPos.y, startPos.x + vec.x, startPos.y + vec.y);
        mathLine(startPos.x, startPos.y, startPos.x + vec.x, startPos.y);
        mathLine(startPos.x + vec.x, startPos.y, startPos.x + vec.x, startPos.y + vec.y);
        stroke(255, 0, 0);
        mathArrow(startPos.x, startPos.y, startPos.x + vec.nx, startPos.y + vec.ny);
        mathLine(startPos.x, startPos.y, startPos.x + vec.nx, startPos.y);
        mathLine(startPos.x + vec.nx, startPos.y, startPos.x + vec.nx, startPos.y + vec.ny);
    }
}
void drawVectorInfo(struct VEC& vec) {
    float size = 45;
    float x = 0, y = size;
    textSize(size);
    fill(0);
    text((let)"ベクトル(" + vec.x + "," + vec.y + ")", x, y); y += size;
    text((let)"ベクトルの大きさ:" + vec.mag, x, y); y += size;
    fill(255, 0, 0);
    text((let)"正規化ベクトル(" + vec.nx + "," + vec.ny + ")", x, y); y += size;
}