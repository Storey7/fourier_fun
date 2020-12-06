#include "circle.h"

CircleClass::CircleClass(int i, int ir)
{
	index = i;
	n = index * 2 + 1;
	posX = 0;
	posY = 0;
	rotateSpeed = 0.02;
	initRadius = ir;
	radius = initRadius * (4 / (n * PI));
	waveType = 0;
	
	//initial values
	angle = 0;
	cosine = 0;
	sine = 0;
	point = {0,0,0};
	prevPoint = { 0,0,0 };
}

CircleClass::~CircleClass()
{
}

void CircleClass::setup()
{

	
}

void CircleClass::update(glm::vec3 prevPoint)
{
	this->prevPoint = prevPoint;
	angle += rotateSpeed;
	angle = ofWrap(angle, 0, TWO_PI);

	if (waveType == 0) { //Square
		radius = initRadius * (4 / (n * PI));
		n = index * 2 + 1;
	}
	else if (waveType == 1) {
		radius = initRadius * (1 / (n * PI));
		n = index+1;
	}

	cosine = cos(n * angle);
	sine = sin(n * angle);

	posX = (radius * cosine);
	posY = (radius * sine);

	point = { posX, posY, 0 } + prevPoint;
}

void CircleClass::draw()
{
	ofPushMatrix();
	//draw the cyan circle that's moving over the yellow circle's perimeter 

	//draw the yellow circle
	//ofSetColor(240, 230, 10);
	//ofDrawCircle(0, 0, initRadius);
	
	ofSetColor(240, 230, 10);
	ofDrawCircle(prevPoint.x, prevPoint.y, radius);

	ofSetColor(140, 140, 255);
	ofTranslate(prevPoint.x, prevPoint.y, 0);
	ofDrawCircle(point, 10);

	ofSetColor(0, 127, 255);
	ofDrawLine(0, 0, point.x, point.y);

	ofPopMatrix();
}

void CircleClass::setWaveType(int w)
{
	waveType = w;
}
