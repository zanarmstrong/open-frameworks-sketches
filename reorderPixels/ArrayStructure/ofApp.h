#pragma once

#include "ofMain.h"
#include "colorObj.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        static bool orderPixels(ofPoint a, ofPoint b);
        static bool reverseOrderPixels(ofVec2f a, ofVec2f b);
        static bool orderColorsBrightness(colorObj a, colorObj b);
        static bool orderColorsHue(colorObj a, colorObj b);
    
    ofImage finalImageBrightness;
    ofVideoGrabber grabber;
    
    ofPoint coords[307200];
    
    int numPixel = 307200;
    
    int width;
    int height;
    
};
