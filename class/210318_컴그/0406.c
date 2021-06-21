//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//float v1[3] = {75.0,400.0,0.0};
//float v2[3] = {150.0,100.0,0.0};
//float v3[3] = {225.0,400.0,0.0};
//float v4[3] = {300.0,100.0,0.0};
//float v5[3] = {375.0,400.0,0.0};
//float v6[3] = {450.0,100.0,0.0};
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
//}
//
//void draw_points()
//{
//	glColor3f(1.0, 0.0, 0.0);
//
//	glPointSize(4);
//	glBegin(GL_POINTS);
//		glVertex3fv(v1);
//		glVertex3fv(v2);
//		glVertex3fv(v3);
//		glVertex3fv(v4);
//		glVertex3fv(v5);
//		glVertex3fv(v6);
//	glEnd();
//}
//
//void draw_lines()
//{
//	glColor3f(1.0, 0.0, 0.0);
//
//	glPointSize(4);
//	glBegin(GL_LINES);
//		glVertex3fv(v1);
//		glVertex3fv(v2);
//		glVertex3fv(v3);
//		glVertex3fv(v4);
//		glVertex3fv(v5);
//		glVertex3fv(v6);
//	glEnd();
//}
//
//void draw_triangle_fan()
//{
//	glColor3f(1.0, 0.0, 0.0);
//
//	glPointSize(4);
//	glBegin(GL_TRIANGLE_FAN);
//		glVertex3fv(v1);
//		glVertex3fv(v2);
//		glVertex3fv(v3);
//		glVertex3fv(v4);
//		glVertex3fv(v5);
//		glVertex3fv(v6);
//	glEnd();
//}
//
//void draw_quads()
//{
//	glColor3f(1.0, 0.0, 0.0);
//
//	glPointSize(4);
//	glBegin(GL_QUADS);
//		glVertex3fv(v1);
//		glVertex3fv(v2);
//		glVertex3fv(v4);
//		glVertex3fv(v3);
//		glVertex3fv(v5);
//		glVertex3fv(v6);
//	glEnd();
//}
//
//void draw_quad_strip()
//{
//	glColor3f(1.0, 0.0, 0.0);
//
//	glPointSize(4);
//	glBegin(GL_QUAD_STRIP);
//		glVertex3fv(v1);
//		glVertex3fv(v2);
//		glVertex3fv(v3);
//		glVertex3fv(v4);
//		glVertex3fv(v5);
//		glVertex3fv(v6);
//	glEnd();
//}
//
//void draw_polygon()
//{
//	glColor3f(1.0, 0.0, 0.0);
//
//	glPointSize(4);
//	glBegin(GL_POLYGON);
//		glVertex3fv(v1);
//		glVertex3fv(v2);
//		glVertex3fv(v4);
//		//glVertex3fv(v6);
//		glVertex3fv(v5);
//		glVertex3fv(v3);
//	glEnd();
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	//draw_points();
//	//draw_lines();
//	draw_triangle_fan();
//	//draw_quads();
//	//draw_quad_strip();
//	//draw_polygon();
//	glFlush();
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(300, 300);
//	glutCreateWindow("My First GL Program");
//	init();
//
//	glutDisplayFunc(display);
//
//	glutMainLoop();
//
//	return 0;
//}