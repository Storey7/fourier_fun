#pragma once
#include "ofMain.h"

class CircleClass {
public:
	CircleClass(int i);
	~CircleClass();

	void setup();
	void update();
	void draw();

	float rotateSpeed;
	float posX;
	float posY;
	float n;

	float rotation = 0.0;
};