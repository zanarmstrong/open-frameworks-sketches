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

bool ofApp::reverseOrderPixels(ofVec2f a, ofVec2f b){
    bool k = orderPixels(a, b);
    return !k;
}

//--------------------------------------------------------------
void ofApp::setup(){

    
    width = 640;
    height = 480;
    
    finalImage.allocate(width, height, OF_IMAGE_GRAYSCALE);
    pixFinal = finalImage.getPixels();
   
    // create a vector of all pixels, and sort them by spiral order from center
    
    for (int i = 0; i < width; i++){
        for (int j = 0; j < height; j++){
            // redefine coordinates from center for sorting, note the offset needed for the center
            coords.push_back(ofVec2f(float(i) - width / 2,float(j) - height / 2));
        }
    }
    
    // sort the ordered pairs of pixels into a spiral, using function declared above
    ofSort(coords, reverseOrderPixels);
    
    // update images
    
    grabber.initGrabber(width,height);
    
}


//--------------------------------------------------------------
void ofApp::update(){

    grabber.update();
    
    bool bFrameNew = grabber.isFrameNew();
    unsigned char * pixels;
    
    if (bFrameNew){
        // comes in as rgb
        pixels = grabber.getPixels();
        
        vector <int> colors;
        
        for (int i = 0; i < width * height; i++){
            // get just the red channel and treat as grey
            colors.push_back(pixels[i * 3]);
        }
        
        ofSort(colors);
        
        //    // walk through the vector of ordered pixels and assign colors in order
        for (int i = 0; i < colors.size(); i++){
            ofVec2f k = coords[i];
            pixFinal[int((k.y + height/2) * width + (k.x + width/2))] = colors[i];
        }
        
        finalImage.update();
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    finalImage.draw(width, 0);
    
    grabber.draw(0,0);
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
