//
//  colorObj.h
//  loadImageIn
//
//  Created by zan on 11/26/14.
//
//

#pragma once

#include <iostream>
#include "ofMain.h"



class colorObj {
    
public:
    void setColor(ofColor color);
    ofColor getColor();
    float getHue();
    float getBrightness();
    float setBrightness();
    
    ofColor pixelColor;
    float pixelHue;
    float pixelBrightness;
    
};
