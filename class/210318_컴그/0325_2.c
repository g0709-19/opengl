//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);	// ������ ����� ���������� ����
//}
//
//void triangle(void)
//{
//	glBegin(GL_TRIANGLES);
//		glColor3f(1.0, 0.0, 0.0);
//		glVertex2f(-0.5, -0.5);
//		glColor3f(0.0, 1.0, 0.0);
//		glVertex2f(0.5, -0.5);
//		glColor3f(0.0, 0.0, 1.0);
//		glVertex2f(-0.5, 0.5);
//	glEnd();
//}
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glFlush();
//}
//
//void mouseProcess(int button, int state, int x, int y)
//{
//	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//		printf("Left mouse button is pressed..\a\n");
//	else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
//		printf("Middle mouse button is pressed..\a\n");
//	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//		printf("Right mouse button is pressed..\a\n");
//	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//		printf("Left mouse button is released..\a\n");
//	else if(button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
//		printf("Middle mouse button is released..\a\n");
//	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
//		printf("Right mouse button is released..\a\n");
//}
//
//void mousePassiveMotion(int x, int y)
//{
//	printf("Current mouse position: %d, %d\n", x, y);
//}
//
//void mouseActiveMotion(int x, int y)
//{
//	printf("Pressed mouse position: %d, %d\n", x, y);
//}
//
//void mouseEntry(int state)
//{
//	if(state == GLUT_LEFT)
//		printf("Mouse is outside of window..\a\n");
//	else if(state == GLUT_ENTERED)
//		printf("Mouse is inside of window..\a\n");
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//		case 'a':
//			printf("a is pressed.. %d, %d\a\n", x, y);
//			break;
//		case 'b':
//			printf("b is pressed.. %d, %d\a\n", x, y);
//			break;
//		case 27:
//			exit(0);
//			break;
//	}
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);	// GLUT ���¸� �ʱ�ȭ
//	// ���÷��̸������ ����: Single buffer & RGBA color ��� ����
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// â�� ũ��� ��ġ ����
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//
//	glutCreateWindow("Mouse and Keyboard");	// ������ ����
//	init();
//
//	// �ʿ��� �ݹ��Լ� ���
//	glutDisplayFunc(display);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouseProcess);
//	glutPassiveMotionFunc(mousePassiveMotion); 
//	glutMotionFunc(mouseActiveMotion);// ������ �������� ����
//	glutEntryFunc(mouseEntry);
//	glutMainLoop();	// �̺�Ʈ ó������ ����
//	return 0;
//}
