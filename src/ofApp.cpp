#include "ofApp.h"
#include "circle.h"
#include <deque>

//https://github.com/openframeworks/openFrameworks/blob/patch-release/examples/math/trigonometryExample/src/ofApp.cpp

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);
	ofBackground(50);

	//initial values
	angle = 0;
	cosine = 0;
	sine = 0;
	tangent = 0;
	rotationSpeed = 0.02;
	initRadius = 150;
	n = 1;
	radius = initRadius * (4 / (n * PI));
	x = 0;
	y = 0;
	center = {ofGetWidth() * 0.3f, ofGetHeight() * 0.6f, 0 };

	ofSetCircleResolution(40);

	gui.setup();
	gui.add(nSlider.setup("n", 1, 1, 80));
	gui.add(waveSlider.setup("Wave Type", 0, 0, 1));
}

//--------------------------------------------------------------
void ofApp::update(){
	
	
	if (circles.size() != nSlider) {
		circles.clear();
		for (int i = 0; i < nSlider; i++) {
			circles.push_back(CircleClass(i));
		}
	}
	if (circles[0].waveType != waveSlider) {
		for (int i = 0; i < nSlider; i++) {
			circles[i].setWaveType(waveSlider);
		}
	}

	circles[0].update({ 0,0,0 });
	prevPointSum = { 0,0,0 };
	for (int i = 1; i < circles.size(); i++)
	{
		prevPointSum += circles[i - 1].point;
		circles[i].update(prevPointSum);
	}
	prevPointSum += circles[circles.size()-1].point;

	wave.push_front(prevPointSum);
	if (wave.size() > 1000)
		wave.pop_back();
}

//--------------------------------------------------------------
void ofApp::draw(){

	gui.draw();
	//we translate everything to the center of the circle so it's easier to draw and understand.
	ofTranslate(center);

	
	for (int i = 0; i < circles.size(); i++)
	{
		circles[i].draw();
	}

	//draw the axis lines
	ofSetColor(20);
	ofSetLineWidth(1);
	ofDrawLine(-radius * 1.3f, 0, radius * 2, 0);
	ofDrawLine(0, -radius * 2, 0, radius * 1.3f);

	//Draw line to wave.
	ofSetColor(255, 0, 50);
	ofSetLineWidth(3);
	ofDrawLine(prevPointSum.x, prevPointSum.y, radius*1.5, wave[0].y);

	//draw the line from the yellow circle's center to the cyan circle 
	ofSetColor(0, 127, 255);
	ofDrawLine(0, 0, point.x, point.y);

	ofPushMatrix();
	ofTranslate(radius*1.5, 0);
	ofBeginShape();
	ofNoFill();
	for (int i = 0; i < wave.size(); i++)
	{
		ofVertex(i, wave[i].y);
	}
	ofEndShape();
	ofPopMatrix();

	
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

void ofApp::ringButtonPressed()
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
