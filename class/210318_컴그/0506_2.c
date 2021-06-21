//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//void display()
//{
//	GLdouble eqn[4] = {0.0, 1.0, 0.0, 0.0};
//	GLdouble eqn2[4] = {1.0, 0.0, 0.0, 0.0};
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glPushMatrix();
//	glTranslatef(0.0, 0.0, -3.0);
//
//	// clip lower half -- y < 0
//	glClipPlane(GL_CLIP_PLANE0, eqn);
//	glEnable(GL_CLIP_PLANE0);
//
//	// clip left half -- x < 0
//	glClipPlane(GL_CLIP_PLANE1, eqn2);
//	glEnable(GL_CLIP_PLANE1);
//
//	glRotatef(90.0, 1.0, 0.0, 0.0);
//	glutWireSphere(1.0, 20, 16);
//	glPopMatrix();
//	glFlush();
//}
//
//void myinit(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void myReshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow(argv[0]);
//	myinit();
//	glutDisplayFunc(display);
//	glutReshapeFunc(myReshape);
//	glutMainLoop();
//	return 0;
//}