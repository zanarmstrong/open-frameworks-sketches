#include "ofApp.h"


//--------------------------------------------------------------
bool ofApp::orderPixels(ofVec2f a, ofVec2f b){
    // goal: return true if a > b
    
    // check if radius a is larger than radius b, using pythagorian theorem
    if(sqrt(a.x * a.x + a.y * a.y) > sqrt(b.x * b.x + b.y * b.y) + 1){
        return true;
    //check if radius b is larger than radius a
    } else if (sqrt(a.x * a.x + a.y * a.y) + 1 < sqrt(b.x * b.x + b.y * b.y)){
        return false;
    // if the radius is within 1, check the angles
    } else {
        // both points below midpoint?
        if(a.y < 0 and b.y < 0){
            // and further left?
            if(a.x < b.x){
                return true;
            } else {
                return false;
            }
        // both points above midpoint?
        } else if(a.y > 0 and b.y > 0){
            // and further right?
            if(a.x > b.x){
                return true;
            } else {
                return false;
            }
        // one point above midpoint, and the other below?
        } else if(a.y > b.y){
            return true;
        } else {
            return false;
        }
    }
}
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

    // create a vector of all pixels, and sort them by spiral order from center
    vector <ofVec2f> coords;
    
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            // redefine coordinates from center for sorting, note the offset needed for the center
            coords.push_back(ofVec2f(float(i) - width / 2,float(j) - height / 2));
        }
    }
    
    // sort the ordered pairs of pixels into a spiral, using function declared above
    ofSort(coords, orderPixels);
    
    // walk through the vector of ordered pixels and assign colors in order
    for (int i = 0; i < colors.size(); i++){
        ofVec2f k = coords[i];
        pixFinal[int((k.y + height/2) * width + (k.x + width/2))] = colors[i];
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
