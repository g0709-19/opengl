//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <GL/glut.h>
//
//static int delay = 10;
//
//void display(void)
//{
//	int x1, y1, x2, y2, r, g, b;
//
//	x1=rand()%50; y1=rand()%50; x2=rand()%50; y2=rand()%50;
//	r = rand()%256; g = rand()%256; b = rand()%256;
//
//	glColor3f((GLfloat)r/255, (GLfloat)g/255, (GLfloat)b/255);
//
//	glBegin(GL_POLYGON);
//		glVertex2f(x1, y1); glVertex2f(x1, y2);
//		glVertex2f(x2, y2); glVertex2f(x2, y1);
//	glEnd();
//
//	glFlush();
//}
//
//void init(void)
//{
//	srand(time(0));
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glColor3f(1.0, 0.0, 0.0);
//	gluOrtho2D(0.0, 50.0, 0.0, 50.0);
//	glClear(GL_COLOR_BUFFER_BIT); // 지워도 잘 되는데
//}
//
//void timer(int t)
//{
//	glutPostRedisplay();
//	glutTimerFunc(delay, timer, t);
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(500, 300);
//	glutCreateWindow("Prog02: Random boxes");
//	glutDisplayFunc(display);
//	glutTimerFunc(delay, timer, 0);
//
//	init();
//	glutMainLoop();
//	return 0;
//}