//
//  spiral.cpp
//  5_sinExample_multiCircles
//
//  Created by zan on 11/4/14.
//
//

#include "spiral.h"

//--------------------------------------------------------------
void spiralObject::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(20,20,20);
	
	ofSetCircleResolution(100);
    
    timeLapsed = 0;
}

//--------------------------------------------------------------
void spiralObject::setOrigin(int x, int y){
    xOrig = x;
    yOrig = y;
}


//--------------------------------------------------------------
void spiralObject::update(){
	
}

//--------------------------------------------------------------

void spiralObject::draw(){
    
    float time = 0;
    if(ofGetElapsedTimef() > 10){
        time = ofGetElapsedTimef() - 10 - timeLapsed;
    };

    
    for (int i = 0; i < 50; i++){
    
        float radius = 5 + i * (time * .3);
        float angle = time * (1 + i / 20.0f);
        while (angle > TWO_PI) angle -= TWO_PI;
        
        float x = xOrig + radius * cos(angle);
        float y = yOrig + radius * -sin(angle);
		
        float colorA = ofMap(angle, 0, TWO_PI, 0, 255);
        float colorB = ofMap(angle + 5, 0, TWO_PI, 0, 255);
        
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofSetColor(colorA,200,colorB);
        
        float sideLength = 7;
        float angleT = time / 3.0f + i / 4.0f;
        
        ofTriangle(x + sideLength * cos(angleT),
                   y + sideLength * sin(angleT),
                   x +  sideLength * cos(angleT + 2* pi/3),
                   y +  sideLength * sin(angleT + 2* pi/3),
                   x +  sideLength * cos(angleT + 4* pi/3),
                   y +  sideLength * sin(angleT + 4 * pi/3));
        
    }

}
