//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);	// 윈도우 배경을 검은색으로 설정
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
//	glutInit(&argc, argv);	// GLUT 상태를 초기화
//	// 디스플레이모드형식 선택: Single buffer & RGBA color 모드 선택
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// 창의 크기와 위치 설정
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//
//	glutCreateWindow("Mouse and Keyboard");	// 윈도우 생성
//	init();
//
//	// 필요한 콜백함수 등록
//	glutDisplayFunc(display);
//	glutKeyboardFunc(keyboard);
//	glutMouseFunc(mouseProcess);
//	glutPassiveMotionFunc(mousePassiveMotion); 
//	glutMotionFunc(mouseActiveMotion);// 누르고 움직여야 반응
//	glutEntryFunc(mouseEntry);
//	glutMainLoop();	// 이벤트 처리엔진 시작
//	return 0;
//}
