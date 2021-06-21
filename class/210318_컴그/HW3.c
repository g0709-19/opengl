///*
//	�� ������ �հ���(3��)�� ������ Robot arm��
//	ǥ���ϴ� ���α׷��� �ۼ��϶�
//	�� ������ ����� ��ó�� ������ ���� �̻��� ������ �� ����
//	Pop-up menu�� �̿��Ͽ� �� ���� ����
//	'u' key�� ȸ���� ����, 'd'�� ȸ���� ����
//	glPushMatrix()�� glPopMatrix()�� ������ ���
//	's' key�� ���θ��� Ư���� �ൿ�� â�������� �߰��� ��
//
//	�ۼ���: 2021�� 5�� 14��(��)
//	�й�: 20184014
//	�̸�: �̽���
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//static int arm = 0;				// ��ü �� ȸ����
//static int special = 0;			// �����Ű ���� ����
//static int shoulder = 0, elbow = 0, hand = 0;		// ���, �Ȳ�ġ, �ո� ȸ����
//static int finger1 = 0, finger2 = 0, finger3 = 0;	// �հ��� ȸ����
//static char mode = 0;			// ȸ�� ����
//static char finger_mode = 0;	// �հ��� ȸ�� ����
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
//	glRotatef(arm, 0.0, 1.0, 0.0);	// �� ��ü ȸ��
//	if (special) {	// s Ű ���� �� ������ ����
//		special = 0;
//		srand(time(NULL));
//		glColor3f(rand()%256/255.0, rand()%256/255.0, rand()%256/255.0);
//	}
//
//	// ��� ����
//	glTranslatef(-1.0, 0.0, 0.0);
//	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
//	glTranslatef(1.0, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	// �Ȳ�ġ ����
//	glTranslatef(1.0, 0.0, 0.0);
//	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
//	glTranslatef(1.0, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(2.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//
//	// �ո� ����
//	glTranslatef(1.0, 0.0, 0.0);
//	glRotatef((GLfloat)hand, 0.0, 0.0, 1.0);
//	glTranslatef(0.5, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(1.0, 0.4, 1.0);
//	glutWireCube(1.0);
//	glPopMatrix();
//	
//	glPushMatrix();	// �� ���� ����
//
//	// �հ��� ����1
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
//	glPushMatrix();	// �� ���� ����
//
//	// �հ��� ����2
//	glTranslatef(0.5, 0.0, 0.0);
//	glRotatef(finger2, 0.0, 0.0, 1.0);
//	glTranslatef(0.5, 0.0, 0.0);
//	glPushMatrix();
//	glScalef(1.0, 0.4, 0.33);
//	glutWireCube(1.0);
//	glPopMatrix();
//	glPopMatrix();
//
//	// �հ��� ����3
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
//// u, d Ű�� �Է� �޾� ȸ������ �����ϴ� �Լ�(�� ���� ȸ�������� ��,������ ����)
//void handleKeyboard(unsigned char key, int x, int y)
//{
//	if (key == 's') {	// �� ��ü
//		arm = (arm + 5) % 360;
//		special = 1;
//	} else {
//		switch(mode)
//		{
//		case 's':		// ��� ����
//			if (key == 'u') {
//				shoulder = (shoulder + 5) % 360;
//				if (shoulder >= 80) shoulder = 80;
//			}
//			else if (key == 'd') {
//				shoulder = (shoulder - 5) % 360;
//				if (shoulder <= -80) shoulder = -80;
//			}
//			break;
//		case 'e':		// �Ȳ�ġ ����
//			if (key == 'u') {
//				elbow = (elbow + 5) % 360;
//				if (elbow >= 135) elbow = 135;
//			}
//			else if (key == 'd') {
//				elbow = (elbow - 5) % 360;
//				if (elbow <= 0) elbow = 0;
//			}
//			break;
//		case 'h':		// �ո� ����
//			if (key == 'u') {
//				hand = (hand + 5) % 360;
//				if (hand >= 80) hand = 80;
//			}
//			else if (key == 'd') {
//				hand = (hand - 5) % 360;
//				if (hand <= -80) hand = -80;
//			}
//			break;
//		case 'f':		// �հ��� ����
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
//// ����
//void reset()
//{
//	mode = 0;
//	finger_mode = 0;
//	arm = shoulder = elbow = hand = finger1 = finger2 = finger3 = 0;
//}
//
//// ���, �Ȳ�ġ, �ո� ����
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
//// �հ��� ����
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
//	// ���� �޴�(�հ���) ����
//	sub_menu = glutCreateMenu(handleFingerMenu);
//	glutAddMenuEntry("First finger", 1);
//	glutAddMenuEntry("Second finger", 2);
//	glutAddMenuEntry("Third finger", 3);
//
//	// ���� �޴�(ȸ�� ����) ����
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