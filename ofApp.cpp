#include "ofApp.h"

ofPlanePrimitive plane;
//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	button.addListener(this, &ofApp::buttonPressed);
	slider.addListener(this, &ofApp::sliderChanged);

	gui.setup();
	gui.add(screenSize.setup("screen size", ofToString(ofGetWidth()) + "x" + ofToString(ofGetHeight())));
	gui.add(slider.setup("select X", 5, 2, 2000));
	gui.add(button.setup("agregar linea"));
	plane.set(640, 480);   ///dimensions for width and height in pixels
	plane.setPosition(500, 300, 0); /// position in x y z

}

void ofApp::exit() {
	button.removeListener(this, &ofApp::buttonPressed);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	
	ofSetColor(255, 255, 255, 255);
	plane.draw();
	gui.draw();
	ofSetColor(0, 0,0, 255);
	line.draw();
	ofSetColor(255, 0, 0, 255);
	lineInter.draw();
	
	
	

}	

void ofApp::buttonPressed() {
	++i;
	cout << i << "\n";
	cout << x << "\n";
	if (limpialinea)
	{
		line.clear();
		lineInter.clear();
		limpialinea = false;
	}
	ofPoint pt;
	ofPoint ptF;
	pt.set(x, 1);
	line.addVertex(pt);
	//agrgar nodos visibles
	//defino los rangos de X y Y
	int inX = plane.getX() - (plane.getWidth() / 2);
	int fiX = plane.getX() + (plane.getWidth() / 2);
	if (x > inX && x < fiX) {
		ofPoint ptDen1;
		ofPoint ptDen2;
		cout << "entre\n";


		ptDen1.set(x, plane.getY() - (plane.getHeight() / 2));
		ptDen2.set(x, plane.getY() + (plane.getHeight() / 2));
		lineInter.addVertex(ptDen1);
		lineInter.addVertex(ptDen2);
		
	}
	ptF.set(x, 900);
	cout << "inicio" << inX << "\n";
	cout << "fin" << fiX << "\n";
	line.addVertex(ptF);
	limpialinea = true;
	

}

void ofApp::sliderChanged(int &slider) {
	x = slider;
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
