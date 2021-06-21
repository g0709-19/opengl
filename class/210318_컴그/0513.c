//#include <stdio.h>
//#include <stdlib.h>
//#include <gl/glut.h>
//#include <gl/glu.h>
//#include <gl/gl.h>
//
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glFlush();
//}
//
//void main_menu_select(int value)
//{
//	switch(value) {
//		case 1:
//			glutSetWindowTitle("First mode..");
//			printf("첫번째 메뉴를 선택하셨습니다..\n");
//			break;
//		case 2:
//			glutSetWindowTitle("Second mode..");
//			printf("두번째 메뉴를 선택하셨습니다..\n");
//			break;
//		case 3:
//			glutSetWindowTitle("Third mode..");
//			printf("세번째 메뉴를 선택하셨습니다..\n");
//			break;
//		case 666:
//			printf("프로그램 종료..\n");
//			exit(0);
//			break;
//	}
//}
//
//int main(int argc, char **argv)
//{
//	glutInitWindowSize(400, 400);
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutCreateWindow("Menu example by Min Hong.");
//	glutDisplayFunc(display);
//	
//	glutCreateMenu(main_menu_select);
//	glutAddMenuEntry("First", 1);
//	glutAddMenuEntry("Second", 2);
//	glutAddMenuEntry("Third", 3);
//	glutAddMenuEntry("Quit", 666);
//
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	glutMainLoop();
//	return 0;
//}