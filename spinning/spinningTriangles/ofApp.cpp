#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetVerticalSync(true);
	
	ofBackground(20,20,20);
	
	ofSetCircleResolution(100);
    
    spiralObject mySpiral;
    mySpiral.setOrigin(ofGetWidth()/2, ofGetHeight()/2);
    
    spirals.push_back(mySpiral);

}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < spirals.size(); i++){
		spirals[i].draw();
	}
    
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
    
    /*  Include this if you want the center to follow the mouse
     // if timeLapsed = 0 it doesn't start over, if it equals ofGetElapsedTimef then it does start over
    timeLapsed = ofGetElapsedTimef();
    
    xorig = x;
    yorig = y;
     */
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    spiralObject mySpiral;
    mySpiral.setOrigin(x, y);
    
    spirals.push_back(mySpiral);

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

