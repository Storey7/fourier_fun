#include "circle.h"

CircleClass::CircleClass(int i)
{
	n = i * 2 + 1;
	posX = 0;
	posY = 0;
	rotateSpeed = 0.02;
	radius = 150 * (4 / (n * PI));
	
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
	radius = 150 * (4 / (n * PI));

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
