#pragma once
#include <GL/glut.h>

class Rotate {
private:
	GLfloat eyeX;
	GLfloat eyeY;
	GLfloat eyeZ;
	GLfloat upX;
	GLfloat upY;
	GLfloat upZ;
public:
	Rotate() : eyeX(0.0), eyeY(0.0), eyeZ(0.0), upX(0.0), upY(0.0), upZ(0.0) {}
	Rotate(double x, double y, double r);

	void LookAt();
};



