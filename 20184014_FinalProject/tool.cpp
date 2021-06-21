#include "tool.h"
#include <cmath>

// 주어진 각도와 거리로 카메라의 이동, 회전 값을 구함
Rotate::Rotate(double x, double y, double r)
{
	// Mouse point to angle conversion
	double theta = y;
	double phi = x;
	// Restrict the angles within 0~360 deg (optional)
	if(theta > 360) theta = fmod((double)theta, 360.0);
	if(phi > 360) phi = fmod((double)phi, 360.0);

	GLfloat dt = 1.0;
	// Reduce theta slightly to obtain another point on the same longitude line on the sphere.
	GLfloat eyeXtemp = r * sin(theta*0.0174532-dt) * sin(phi*0.0174532);
	GLfloat eyeYtemp = r * cos(theta*0.0174532-dt);
	GLfloat eyeZtemp = r * sin(theta*0.0174532-dt) * cos(phi*0.0174532);

	// Spherical to Carthesian conversion.
	eyeX = r * sin(theta*0.0174532) * sin(phi*0.0174532);
	eyeY = r * cos(theta*0.0174532);
	eyeZ = r * sin(theta*0.0174532) * cos(phi*0.0174532);

	upX = eyeXtemp  - eyeX;
	upY = eyeYtemp - eyeY;
	upZ = eyeZtemp - eyeZ;
}

// 카메라의 좌표, 회전 적용
void Rotate::LookAt()
{
	gluLookAt(eyeX, eyeY, eyeZ, 0.0, 0.0, 0.0, upX, upY, upZ);
}