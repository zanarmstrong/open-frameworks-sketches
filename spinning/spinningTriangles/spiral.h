//
//  spiral.h
//  5_sinExample_multiCircles
//
//  Created by zan on 11/4/14.
//
//

#pragma once

// so I can use OF classes
#include "ofMain.h"

class spiralObject {
    
    public:
        void setup();
        void update();
        void draw();
    
        void setOrigin(int x, int y);
    
    float xOrig;
    float yOrig;
    float timeLapsed;
    
};
