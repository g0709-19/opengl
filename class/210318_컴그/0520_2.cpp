//#include <stdio.h>
//#include <stdlib.h>
//#include <gl/glut.h>
//#include <gl/glu.h>
//#include <gl/gl.h>
//#include <math.h>
//
//GLint winWidth=600, winHeight=600;
//GLfloat eyeX=0.0, eyeY=0.0, eyeZ=2.0;
//GLfloat theta=270.0, phi=180.0;
//GLfloat upX=0.0, upY=1.0, upZ=0.0;
//GLfloat r=2.0;
//
//void draw_cube()
//{
//	// 앞쪽면
//	glBegin(GL_POLYGON);
//		glColor3f(1.0, 1.0, 1.0);	// White
//		glVertex3f(0.5, 0.5, 0.5);
//		glColor3f(1.0, 0.0, 1.0);	// Magenta
//		glVertex3f(-0.5, 0.5, 0.5);
//		glColor3f(1.0, 0.0, 0.0);	// Red
//		glVertex3f(-0.5, -0.5, 0.5);
//		glColor3f(1.0, 1.0, 0.0);	// Yellow
//		glVertex3f(0.5, -0.5, 0.5);
//	glEnd();
//
//	// 오른쪽 면
//	glBegin(GL_POLYGON);
//		glColor3f(1.0, 1.0, 1.0);	// White
//		glVertex3f(0.5, 0.5, 0.5);
//		glColor3f(1.0, 1.0, 0.0);	// Yellow
//		glVertex3f(0.5, -0.5, 0.5);
//		glColor3f(0.0, 1.0, 0.0);	// Green
//		glVertex3f(0.5, -0.5, -0.5);
//		glColor3f(0.0, 1.0, 1.0);	// Cyan
//		glVertex3f(0.5, 0.5, -0.5);
//	glEnd();
//
//	// 위쪽 면
//	glBegin(GL_POLYGON);
//		glColor3f(1.0, 0.0, 1.0);	// Magenta
//		glVertex3f(-0.5, 0.5, 0.5);
//		glColor3f(1.0, 1.0, 1.0);	// White
//		glVertex3f(0.5, 0.5, 0.5);
//		glColor3f(0.0, 1.0, 1.0);	// Cyan
//		glVertex3f(0.5, 0.5, -0.5);
//		glColor3f(0.0, 0.0, 1.0);	// Blue
//		glVertex3f(-0.5, 0.5, -0.5);
//	glEnd();
//
//	// 왼쪽 면
//	glBegin(GL_POLYGON);
//		glColor3f(1.0, 0.0, 1.0);	// Magenta
//		glVertex3f(-0.5, 0.5, 0.5);
//		glColor3f(0.0, 0.0, 1.0);	// Blue
//		glVertex3f(-0.5, 0.5, -0.5);
//		glColor3f(0.0, 0.0, 0.0);	// Black
//		glVertex3f(-0.5, -0.5, -0.5);
//		glColor3f(1.0, 0.0, 0.0);	// Red
//		glVertex3f(-0.5, -0.5, 0.5);
//	glEnd();
//
//	// 아래쪽 면
//	glBegin(GL_POLYGON);
//		glColor3f(1.0, 0.0, 0.0);	// Red
//		glVertex3f(-0.5, -0.5, 0.5);
//		glColor3f(0.0, 0.0, 0.0);	// Black
//		glVertex3f(-0.5, -0.5, -0.5);
//		glColor3f(0.0, 1.0, 0.0);	// Green
//		glVertex3f(0.5, -0.5, -0.5);
//		glColor3f(1.0, 1.0, 0.0);	// Yellow
//		glVertex3f(0.5, -0.5, 0.5);
//	glEnd();
//
//	// 뒤쪽 면
//	glBegin(GL_POLYGON);
//		glColor3f(0.0, 0.0, 1.0);	// Blue
//		glVertex3f(-0.5, 0.5, -0.5);
//		glColor3f(0.0, 1.0, 1.0);	// Cyan
//		glVertex3f(0.5, 0.5, -0.5);
//		glColor3f(0.0, 1.0, 0.0);	// Green
//		glVertex3f(0.5, -0.5, -0.5);
//		glColor3f(0.0, 0.0, 0.0);	// Black
//		glVertex3f(-0.5, -0.5, -0.5);
//	glEnd();
//}
//
//void init()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glEnable(GL_DEPTH_TEST);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1, 1, -1, 1, 0.6, 300);
//}
//
//void displayFcn()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glMatrixMode(GL_MODELVIEW);	// set to Model View before drawing
//	glLoadIdentity();
//	gluLookAt(eyeX, eyeY, eyeZ, 0, 0, 0, upX, upY, upZ);
//
//	glPolygonMode(GL_FRONT, GL_FILL);
//	draw_cube();
//
//	glutSwapBuffers();
//}
//
//void reshapeFcn(GLint newWidth, GLint newHeight)
//{
//	glViewport(0, 0, newWidth, newHeight);
//	winWidth=newWidth;
//	winHeight=newHeight;
//}
//
//// OpenGL/GLUT C code (by H. Shirokawa)
//void eyePosition(void)
//{
//	GLfloat dt = 1.0;
//	// Reduce theta slightly to obtain another point on the same longitude line on the sphere.
//	GLfloat eyeXtemp = r * sin(theta*0.0174532-dt) * sin(phi*0.0174532);
//	GLfloat eyeYtemp = r * cos(theta*0.0174532-dt);
//	GLfloat eyeZtemp = r * sin(theta*0.0174532-dt) * cos(phi*0.0174532);
//
//	// Spherical to Carthesian conversion.
//	eyeX = r * sin(theta*0.0174532) * sin(phi*0.0174532);
//	eyeY = r * cos(theta*0.0174532);
//	eyeZ = r * sin(theta*0.0174532) * cos(phi*0.0174532);
//
//	upX = eyeXtemp  - eyeX;
//	upY = eyeYtemp - eyeY;
//	upZ = eyeZtemp - eyeZ;
//
//	glutPostRedisplay();
//}
//
//// OpenGL/GLUT C code (by H. Shirokawa)
//void onMouseMove(int x, int y)
//{
//	// Mouse point to angle conversion
//	theta = (360.0/(double)winHeight)*(double)(y*3.0); // 3.0 rotations possible
//	phi = (360.0/(double)winWidth)*(double)x*3.0;
//	// Restrict the angles within 0~360 deg (optional)
//	if(theta > 360) theta = fmod((double)theta, 360.0);
//	if(phi > 360) phi = fmod((double)phi, 360.0);
//	eyePosition();
//}
//
//void SpecialKeys(int key, int x, int y)
//{
//	if(key == GLUT_KEY_UP)		r -= 0.1;
//	if (key == GLUT_KEY_DOWN)	r += 0.1;
//
//	eyePosition();
//}
//
//void main(int argc, char ** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowPosition(50, 50);
//	glutInitWindowSize(winWidth, winHeight);
//	glutCreateWindow("Camera & RGB Color Cube");
//
//	init();
//	glutDisplayFunc(displayFcn);
//	glutReshapeFunc(reshapeFcn);
//	glutPassiveMotionFunc(onMouseMove);
//	glutSpecialFunc(SpecialKeys);
//	glutMainLoop();
//}