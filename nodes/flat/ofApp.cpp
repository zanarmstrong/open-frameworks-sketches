#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(50);
    
    myNode.setGlobalPosition(ofPoint(0,0,0));
    myNode2.setParent(myNode);
    // setGlobalPosition is global while setPosition is relative
    myNode2.setPosition(ofPoint(300,0,0));
    
    myNode3.setParent(myNode2);
    myNode3.setPosition(ofPoint(100,0,0));

    
    
}

//--------------------------------------------------------------
void ofApp::update(){
  //  myNode.lookAt(ofPoint(mouseX, mouseY, 0));
    
    myNode.pan(1.4);
    myNode2.setPosition(35 + 200 * sin(ofGetElapsedTimef()),0,0);
    myNode2.tilt(1.2);
    
    myline.addVertex(myNode3.getGlobalPosition());
  //  if(myline.size() > 1000){
  //      myline.getVertices().erase(myline.getVertices().begin());
  //  }
}

//--------------------------------------------------------------
void ofApp::draw(){

    myCam.begin();
    ofEnableDepthTest();
    
  //  myNode.draw();
  //  myNode2.draw();
  //  myNode3.draw();
    
    myline.draw();
    myCam.end();
    
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
