//
//  colorObj.cpp
//  loadImageIn
//
//  Created by zan on 11/26/14.
//
//

#include "colorObj.h"


//--------------------------------------------------------------
void colorObj::setColor(ofColor color){
    pixelColor = color;
    //  pixelHue = color.getHue();
    pixelBrightness = pixelColor.getBrightness();
}

//--------------------------------------------------------------
//float colorObj::setBrightness(){
//}

//--------------------------------------------------------------
float colorObj::getBrightness(){
	return pixelBrightness;
}

//--------------------------------------------------------------
float colorObj::getHue(){
	return pixelHue;
}

//--------------------------------------------------------------
ofColor colorObj::getColor(){
	return pixelColor;
}
