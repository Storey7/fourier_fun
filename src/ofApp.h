#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "circle.h"

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
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void ringButtonPressed();

		float angle;
		float sine;
		float cosine;
		float tangent;
		float rotationSpeed;

		float radius;
		float initRadius;
		float n;
		float x;
		float y;
		float prevX;
		float prevY;

		ofxIntSlider nSlider;
		ofxIntSlider waveSlider;
		ofxPanel gui;

		glm::vec3 center;
		glm::vec3 point;

		ofPath angleArc;
		
		deque<glm::vec3> wave;
		vector<CircleClass> circles;
		glm::vec3 prevPointSum;

};
