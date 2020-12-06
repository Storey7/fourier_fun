#pragma once
#include "ofMain.h"

class CircleClass {
public:
	CircleClass(int i, int ir);
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
	float radius;
	int initRadius;
private:
	float rotation = 0.0;
};