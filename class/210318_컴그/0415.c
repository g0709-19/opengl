//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//
//void draw_square()
//{
//	glBegin(GL_POLYGON);
//		glVertex2f(-0.5, -0.5);
//		glVertex2f(-0.5, 0.5);
//		glVertex2f(0.5, 0.5);
//		glVertex2f(0.5, -0.5);
//	glEnd();
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glViewport(0, 0, 400, 400);
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_LINES);
//		glVertex2f(-1.0, 0);
//		glVertex2f(1.0, 0);
//		glVertex2f(0.0, -1.0);
//		glVertex2f(0.0, 1.0);
//	glEnd();
//
//	glViewport(0, 0, 200, 200);
//	glColor3f(0.0, 1.0, 0.0);
//	draw_square();
//
//	glViewport(0, 200, 200, 200);
//	glColor3f(1.0, 0.0, 1.0);
//	draw_square();
//
//	glViewport(200, 0, 200, 200);
//	glColor3f(1.0, 1.0, 0.0);
//	draw_square();
//
//	glViewport(200, 200, 200, 200);
//	glColor3f(0.0, 0.0, 1.0);
//	draw_square();
//
//	glFlush();
//}
//
//void init()
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glColor3f(1.0, 1.0, 1.0);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//}
//
//int main(int argc, char ** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowPosition(100, 100);
//	glutInitWindowSize(400, 400);
//	glutCreateWindow("glViewport Example");
//	init();
//	glutDisplayFunc(display);
//	glutMainLoop();
//}