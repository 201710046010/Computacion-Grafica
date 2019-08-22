#pragma once

#include "ofMain.h"
#include "ofxGui.h"


class ofApp : public ofBaseApp{

	public:
		ofxIntSlider slider;
		ofxPanel gui;
		ofxButton button;
		ofPolyline line;
		ofxIntField sectorinI;
		ofParameter < bool > ofParExample;
		ofxLabel screenSize;
		ofPolyline lineInter;
		bool limpialinea = false;
		int x = 0;
		int i = 0;
 
   
		void setup();
		void update();
		void draw();

		void buttonPressed();
		void exit();
		void sliderChanged(int &slider);

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
