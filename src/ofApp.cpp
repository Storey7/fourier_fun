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

	angleArc.setCircleResolution(360);
	angleArc.setFilled(true);
	angleArc.setColor(ofColor(240, 130, 10));

	gui.setup();
	gui.add(nSlider.setup("n", 1, 0, 10));
}

//--------------------------------------------------------------
void ofApp::update(){

	angle += rotationSpeed;//at each update the angle get's incremented 
	//n = nSlider;
	//if the angle is more than or equal to two PI (a full rotation measured in Radians) then make it zero.
	angle = ofWrap(angle, 0, TWO_PI);

	radius = initRadius;

	//here we get the sine and cosine values for the angle
	cosine = cos(n * angle);
	sine = sin(n * angle);

	n = 1;
		
	radius = initRadius * (4 / (n * PI));
	
	//here we get the sine and cosine values for the angle
	cosine = cos(n * angle);
	sine = sin(n * angle);

	x = (radius * cosine);
	y = (radius * sine);

	point = { x, y, 0 };
	
	wave.push_front(point);
	if (wave.size() > 1000)
		wave.pop_back();
}

//--------------------------------------------------------------
void ofApp::draw(){

	gui.draw();
	//we translate everything to the center of the circle so it's easier to draw and understand.
	ofTranslate(center);

	ofNoFill();
	//draw the yellow circle
	//ofSetColor(240, 230, 10);
	//ofDrawCircle(0, 0, initRadius);
	ofSetColor(240, 230, 10);
	ofDrawCircle(0, 0, radius);

	//draw the cyan circle that's moving over the yellow circle's perimeter 
	ofSetColor(0, 140, 255);
	ofDrawCircle(point, 10);


	//draw the axis lines
	ofSetColor(20);
	ofSetLineWidth(1);
	ofDrawLine(-radius * 1.3f, 0, radius * 2, 0);
	ofDrawLine(0, -radius * 2, 0, radius * 1.3f);

	ofSetColor(255, 0, 50);
	ofDrawLine(point.x, point.y, radius*1.5, wave[0].y);

	ofSetLineWidth(3);


	//draw the line from the yellow circle's center to the cyan circle 
	ofSetColor(0, 127, 255);
	ofDrawLine(0, 0, point.x, point.y);


	// draw the info text
	ofSetColor(30);
	ofDrawBitmapString("Angle (DEG): " + ofToString(ofRadToDeg(angle)), 3, 20);

	ofDrawBitmapString("Radius: " + ofToString(radius), -radius + 20, -3);

	ofSetColor(220);
	ofDrawBitmapString("Angle Sine: " + ofToString(sine), radius * 2 + 3, 0);
	ofDrawBitmapString("sine x radius: " + ofToString(sine * radius), radius * 2 + 3, 15);

	ofDrawBitmapString("Angle cosine: " + ofToString(cosine), 0, -radius * 2 - 20);
	ofDrawBitmapString("cosine x radius: " + ofToString(cosine * radius), 0, -radius * 2 - 5);

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

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
