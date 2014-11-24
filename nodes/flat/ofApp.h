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
    
    // a node is a position and direction in 3-d space
    ofNode myNode;
    ofNode myNode2;
    ofNode myNode3;
    
    // like a vector of points
    ofPolyline myline;
    
    // generally cameras are set up so that 0,0,0 is in the center, and they're looking at it
    ofEasyCam myCam;
		
};
