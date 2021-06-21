//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <GL/glut.h>
//
//#define SIZE	50.0
//
//float w_height = 800;
//float w_width = 800;
//float square_x = 0, square_y = 400;
//float square_dx = 5.0;
//
//void idleCallBack()
//{
//	square_x += square_dx;
//	if (square_dx >= 0) square_dx += 0.1;
//	else square_dx -= 0.1;
//	
//	if (square_x + SIZE >= w_width || square_x <= 0) {
//		square_dx /= abs(square_dx);
//		square_dx *= 5.0;
//		square_dx *= -1.0;
//	}
//	glutPostRedisplay();
//}
//
//void displayCallBack()
//{
//	glClearColor(0.0, 0.0, 0.0, 1.0);
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, w_width, 0.0, w_height, -1.0, 1.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(square_x, square_y, 0.0);
//
//	glColor3ub(255, 255, 0);
//	glBegin(GL_POLYGON);
//		glVertex2f(0, 0);
//		glVertex2f(SIZE, 0);
//		glVertex2f(SIZE, SIZE);
//		glVertex2f(0, SIZE);
//	glEnd();
//
//	glutSwapBuffers();
//}
//
//int main(int argc, char **argv)
//{
//	glutInit(&argc, argv);
//
//	glutInitWindowPosition(10, 10);
//	glutInitWindowSize(w_width, w_height);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutCreateWindow("Idle Callback");
//
//	glutDisplayFunc(displayCallBack);
//	glutIdleFunc(idleCallBack);
//
//	glutMainLoop();
//	return 0;
//}