//#include <stdlib.h>
//#include <GL/glut.h>
//
//void display(void)
//{
//	glColor3f(1.0, 1.0, 1.0);	// ������� ����
//
//	// �簢���� ��ǥ �Է�
//	glBegin(GL_LINE_LOOP);
//		glVertex3f(0.25, 0.25, 0.0);
//		glVertex3f(0.75, 0.25, 0.0);
//		glVertex3f(0.75, 0.75, 0.0);
//		glVertex3f(0.25, 0.75, 0.0);
//	glEnd();
//
//	glFlush();	//�簢���� ȭ�鿡 �׸�
//}
//
//void init(void)
//{
//	// ������¡ �� ���������� �ʱ�ȭ �ǳ�
//	glClearColor(0.0, 0.0, 0.0, 0.0);	// ������ ����� ���������� ����
//	glClear(GL_COLOR_BUFFER_BIT);	// ���� ���۸� ����. ����� ���� ǥ�� �ȵ�
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();	// ���� ���
//
//	// ���� ����: left, right, bottom, top, near, far
//	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);	// GLUT ���¸� �ʱ�ȭ
//	// ���÷��̸������ ����: Single buffer & RGBA color ��� ����
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// â�� ũ��� ��ġ ����
//	glutInitWindowSize(250, 250);
//	glutInitWindowPosition(100, 100);
//
//	glutCreateWindow("01 �簢�� �׸���");	// ������ ����
//	init();
//
//	// �ʿ��� �ݹ��Լ� ���
//	glutDisplayFunc(display);
//	glutMainLoop();	// �̺�Ʈ ó������ ����
//	return 0;
//}