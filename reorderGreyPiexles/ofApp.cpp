#include "ofApp.h"


//

//--------------------------------------------------------------
void ofApp::setup(){

    baseImage.loadImage("bwEinstein.png");
    baseImage.setImageType(OF_IMAGE_GRAYSCALE);
    unsigned char * pixOrig = baseImage.getPixels();
    
    width = baseImage.getWidth();
    height = baseImage.getHeight();
    
    finalImage.allocate(width, height, OF_IMAGE_GRAYSCALE);
    unsigned char * pixFinal = finalImage.getPixels();
    
    vector <int> colors;
    
    for (int i = 0; i < width * height; i++){
        colors.push_back(pixOrig[i]);
    }

    ofSort(colors);
    
    for (int i = 0; i < width * height; i++){
        pixFinal[i] = colors[colors.size() - i];
    }
    
    // update images
    baseImage.update();
    finalImage.update();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    baseImage.draw(0,0);
    finalImage.draw(width, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
