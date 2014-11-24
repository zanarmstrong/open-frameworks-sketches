#pragma once

#include "ofMain.h"

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
    
    
    ofImage finalImage;
    ofVideoGrabber grabber;
    vector <ofPoint> coords;
    unsigned char * pixFinal;
    
    int width;
    int height;
    
};
