///*
//	팔 관절과 손가락(3개)를 가지는 Robot arm을
//	표현하는 프로그램을 작성하라
//	각 관절은 사람의 팔처럼 일정한 각도 이상을 움직일 수 없음
//	Pop-up menu를 이용하여 각 관절 선택
//	'u' key는 회전각 증가, 'd'는 회전각 감소
//	glPushMatrix()와 glPopMatrix()를 적절히 사용
//	's' key는 본인만의 특별한 행동을 창조적으로 추가할 것
//
//	작성일: 2021년 5월 14일(금)
//	학번: 20184014
//	이름: 이승준
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//static int arm = 0;				// 전체 팔 회전각
//static int special = 0;			// 스페셜키 누른 여부
//static int shoulder = 0, elbow = 0, hand = 0;		// 어깨, 팔꿈치, 손목 회전각
//static int finger1 = 0, finger2 = 0, finger3 = 0;	// 손가락 회전각
//static char mode = 0;			// 회전 부위
//static char finger_mode = 0;	// 손가락 회전 부위
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
//	glPushMatrix();
//
//	glRotatef(arm, 0.0, 1.0, 0.0);	// 팔 전체 회전
//	if (special) {	// s 키 누를 시 랜덤색 변경
//		special = 0;
//		srand(time(NULL));
//		glColor3f(rand()%256/255.0, rand()%256/255.0, rand()%256/255.0);
//	}
//
//	// 어깨 관절
//	glTranslatef(-1.0, 0.0, 0.0);
//	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
//	glTranslatef(1.0, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	// 팔꿈치 관절
//	glTranslatef(1.0, 0.0, 0.0);
//	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
//	glTranslatef(1.0, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	// 손목 관절
//	glTranslatef(1.0, 0.0, 0.0);
//	glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
//	glTranslatef(0.5, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(1.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//	
//	glPushMatrix();	// 현 상태 저장
//
//	// 손가락 관절1
//	glTranslatef(0.0, 0.0, -0.33);
//	glTranslatef(0.5, 0.0, 0.0);
//	glRotatef(finger1, 0.0, 0.0, 1.0);
//	glTranslatef(0.5, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(1.0, 0.4, 0.33);
//	glutWireCube(1.0);
//	glPopMatrix();
//	glPopMatrix();
//
//	glPushMatrix();	// 현 상태 저장
//
//	// 손가락 관절2
//	glTranslatef(0.5, 0.0, 0.0);
//	glRotatef(finger2, 0.0, 0.0, 1.0);
//	glTranslatef(0.5, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(1.0, 0.4, 0.33);
//	glutWireCube(1.0);
//	glPopMatrix();
//	glPopMatrix();
//
//	// 손가락 관절3
//	glTranslatef(0.0, 0.0, 0.33);
//	glTranslatef(0.5, 0.0, 0.0);
//	glRotatef(finger3, 0.0, 0.0, 1.0);
//	glTranslatef(0.5, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(1.0, 0.4, 0.33);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(65.0, (GLfloat)w/(GLfloat)h, 1.0, 20.0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	glTranslatef(0.0, 0.0, -10.0);
//}
//
//// u, d 키를 입력 받아 회전각을 조절하는 함수(각 관절 회전각에는 상,하한이 있음)
//void handleKeyboard(unsigned char key, int x, int y)
//{
//	if (key == 's') {	// 팔 전체
//		arm = (arm + 5) % 360;
//		special = 1;
//	} else {
//		switch(mode)
//		{
//		case 's':		// 어깨 관절
//			if (key == 'u') {
//				shoulder = (shoulder + 5) % 360;
//				if (shoulder >= 80) shoulder = 80;
//			}
//			else if (key == 'd') {
//				shoulder = (shoulder - 5) % 360;
//				if (shoulder <= -80) shoulder = -80;
//			}
//			break;
//		case 'e':		// 팔꿈치 관절
//			if (key == 'u') {
//				elbow = (elbow + 5) % 360;
//				if (elbow >= 135) elbow = 135;
//			}
//			else if (key == 'd') {
//				elbow = (elbow - 5) % 360;
//				if (elbow <= 0) elbow = 0;
//			}
//			break;
//		case 'h':		// 손목 관절
//			if (key == 'u') {
//				hand = (hand + 5) % 360;
//				if (hand >= 80) hand = 80;
//			}
//			else if (key == 'd') {
//				hand = (hand - 5) % 360;
//				if (hand <= -80) hand = -80;
//			}
//			break;
//		case 'f':		// 손가락 관절
//			if (key == 'u') {
//				if (finger_mode == 1)
//					finger1 = (finger1 + 5) % 360;
//				else if (finger_mode == 2)
//					finger2 = (finger2 + 5) % 360;
//				else if (finger_mode == 3)
//					finger3 = (finger3 + 5) % 360;
//			}
//			else if (key == 'd') {
//				if (finger_mode == 1)
//					finger1 = (finger1 - 5) % 360;
//				else if (finger_mode == 2)
//					finger2 = (finger2 - 5) % 360;
//				else if (finger_mode == 3)
//					finger3 = (finger3 - 5) % 360;
//			}
//			if (finger1 >= 80) finger1 = 80;
//			if (finger2 >= 80) finger2 = 80;
//			if (finger3 >= 80) finger3 = 80;
//			if (finger1 <= -80) finger1 = -80;
//			if (finger2 <= -80) finger2 = -80;
//			if (finger3 <= -80) finger3 = -80;
//			break;
//		default:
//			break;
//		}
//	}
//
//	glutPostRedisplay();
//}
//
//// 리셋
//void reset()
//{
//	mode = 0;
//	finger_mode = 0;
//	arm = shoulder = elbow = hand = finger1 = finger2 = finger3 = 0;
//}
//
//// 어깨, 팔꿈치, 손목 선택
//void handleMainMenu(int index)
//{
//	if (index == 1) {
//		mode = 's';
//		printf("Shoulder selected\n");
//	}
//	else if (index == 2) {
//		mode = 'e';
//		printf("Elbow selected\n");
//	}
//	else if (index == 3) {
//		mode = 'h';
//		printf("Hand selected\n");
//	}
//	else if (index == 5) {
//		reset();
//		printf("Reset\n");
//	}
//	else if (index == 6)
//		exit(0);
//	glutPostRedisplay();
//}
//
//// 손가락 선택
//void handleFingerMenu(int index)
//{
//	if (index == 1) {
//		mode = 'f';
//		finger_mode = 1;
//		printf("First finger selected\n");		
//	}
//	else if (index == 2) {
//		mode = 'f';
//		finger_mode = 2;
//		printf("Second finger selected\n");		
//	}
//	else if (index == 3) {
//		mode = 'f';
//		finger_mode = 3;
//		printf("Third finger selected\n");		
//	}
//
//	glutPostRedisplay();
//}
//
//int main(int argc, char ** argv)
//{
//	GLint sub_menu, main_menu;
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(500, 500);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//
//	init();
//
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutKeyboardFunc(handleKeyboard);
//
//	// 서브 메뉴(손가락) 생성
//	sub_menu = glutCreateMenu(handleFingerMenu);
//	glutAddMenuEntry("First finger", 1);
//	glutAddMenuEntry("Second finger", 2);
//	glutAddMenuEntry("Third finger", 3);
//
//	// 메인 메뉴(회전 부위) 생성
//	main_menu = glutCreateMenu(handleMainMenu);
//	glutAddMenuEntry("Shoulder", 1);
//	glutAddMenuEntry("Elbow", 2);
//	glutAddMenuEntry("Hand", 3);
//	glutAddSubMenu("Finger", sub_menu);
//	glutAddMenuEntry("Reset", 5);
//	glutAddMenuEntry("Exit", 6);
//
//	glutAttachMenu(GLUT_RIGHT_BUTTON);
//
//	glutMainLoop();
//
//	return 0;
//}