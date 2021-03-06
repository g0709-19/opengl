//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//	glLoadIdentity();	// 행렬 초기화
//
//	/* Viewing Transformation */
//	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
//	/* Modeling Transformation */
//	glScalef(1.0, 2.0, 1.0);
//	glutWireCube(1.0);
//	glFlush();
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();	// 행렬 초기화
//	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Transformed Cube");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}