#pragma once
#include "ofMain.h"

class CircleClass {
public:
	CircleClass(int i);
	~CircleClass();

	void setup();
	void update(glm::vec3 prevPoint);
	void draw();
	void setWaveType(int waveType);

	float rotateSpeed;
	float posX;
	float posY;
	float n;
	int index;

	//initial values
	float angle;
	float cosine;
	float sine;
	glm::vec3 point;
	glm::vec3 prevPoint;

	int waveType;
private:

	float rotation = 0.0;
	float radius;
};