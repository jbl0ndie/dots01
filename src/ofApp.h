#pragma once

#include "ofMain.h"
#include <iostream>

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
		
        float circleRadius;
        int numberOfCircles;
        int circleArray[200][200];
        float rotationAngle;
        float rotationSpeed;
    
    // fill a 2D array with random x and y coordinates
   
    ofFbo fbo; // instantiate an FBO object
    
    
    // pass the 2D array as arguments into a function that draws circles at the
    // array coordinates, with the radius as a separate argument to the function
    // this is because we only need to generate one set of random coordinates
    // then draw the same ones each draw,
    // not to create random positions on each draw
    
//    void drawCircle(float circleXPos, float circleYPos, float circleRadius) {
    void drawCircle(float circleRadius) {
        int i;
        int j;
        for (i=0; i<4; i++) {
            for (j=0; j<200; j++) {
                ofCircle(circleArray[i][j], circleArray[j][i], circleRadius);

            }
        };
    };

    
};

