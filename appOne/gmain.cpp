#include"libOne.h"
#include"vector2D.h"
#include"unko.h"

void gmain(){
    window(1920, 1080, true);
    struct VEC vec;
    struct UNKO unko[2];
    int sw = 0;
    int flag = 1;
    createUnko(unko);
    while (notQuit){
        if (isTrigger(KEY_Z))sw = 1 - sw;
        struct POS& startPos = unko[sw].pos;
        struct POS& endPos = unko[1-sw].pos;
        
        dragUnko(unko);
        createVector(&vec, startPos, endPos);
        moveUnko(&startPos, endPos, vec);

        clear(200, 255, 200);
        mathAxis(9.1f);
        drawUnko(unko);

        if (isTrigger(KEY_X))flag = 1 - flag;
        if(flag)drawVector(POS(0,0),vec);
        else drawVector(startPos,vec);
        
        drawVectorInfo(vec);
    }
}
