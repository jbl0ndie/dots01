#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(30);
    
    ofBackground(0);
//    ofSetColor(255);
    
    fbo.allocate(ofGetWindowWidth(), ofGetWindowHeight(), GL_RGBA); // set up FBO with alpha, 8 bits rgb
    
    fbo.begin();
    ofClear(255, 255, 255, 0);  // it's good practice to clear the FBO after allocating it
    fbo.end();
    
    // experimenting with alpha blending and blending modes
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    rotationAngle = 0;
    rotationSpeed = 0.8; // 0.1 is good
    
    int i;
    int j;
    
    for (i=0; i<200; i++) {
        
        for (j=0; j<200; j++)
            circleArray[i][j] = ofRandom(-2000, 2000);
        
    }
    for (i = 0; i <200; i++) {
        for (j=0; j<200; j++) {
            cout << circleArray[i][j] << '\n';
        }
    }
    return 0;
}

//--------------------------------------------------------------
void ofApp::update(){

    rotationAngle += rotationSpeed;
    
    float alpha = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
    fbo.begin();
    ofSetColor(255, 255, 255, alpha);
    ofRect(0, 0, 400, 400);
    
    ofPushMatrix();
        ofSetColor(255, 255, 255, 255);
        ofTranslate(ofGetWindowWidth()/1.8, ofGetWindowHeight()/2.2);
        ofRotate( rotationAngle, 0, 0, 1 ); // Set cemtre of rotation to mid-point
        ofPushMatrix();
            ofTranslate(-ofGetWindowWidth()/2+ofGetFrameNum()/5, -ofGetWindowHeight()/2); // Reset draw position to 0,0
            drawCircle(1);
        ofPopMatrix();
    ofPopMatrix();
    
    fbo.end();
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    // Draw the first set of dots, filling the whole screen area
    // Perhaps these need to be underneath to give the illusion of the alpha mask in the real thing
    // Perhaps alpha mask is the key
    
    // There's a suggestion that ofFbo holds the key.
    // If you can work out the alpha mask example, you should be able to do it
    // What we need is bottom layer to be black with white dots
    // Top layer to be black, rotating, with transparent dots
    
    ofSetColor(255, 127, 0);  // Set orange colour
    ofRect(200, 200, 400, 400); // Draw a fixed square, offset
    
    ofSetColor(255, 255, 255, 255);
    fbo.draw(0, 0);  // draw the FBO to the screen
    
    ofPushMatrix();
    ofSetColor(0,0,0,255);
    drawCircle(15);
    ofPopMatrix();
    
    // Draw a duplicate set of dots but then rotate them about the centrepoint of the screen
//    ofSetColor(255, 127, 0);  // Debug with orange dots on top
//    ofPushMatrix();
//        ofSetBackgroundColor(0);
//    ofSetColor(255, 255, 255, 255);
//        ofTranslate(ofGetWindowWidth()/1.8, ofGetWindowHeight()/2.2);
//        ofRotate( rotationAngle, 0, 0, 1 ); // Set cemtre of rotation to mid-point
//        ofPushMatrix();
//            ofTranslate(-ofGetWindowWidth()/2, -ofGetWindowHeight()/2); // Reset draw position to 0,0
//            drawCircle(15);
//        ofPopMatrix();
//    ofPopMatrix();
    
    
    
    //Print fps at top right of window
    ofDrawBitmapString(ofToString(ofGetFrameRate())+"fps", ofGetWindowWidth()-100, 15);
};

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
