//#include <stdlib.h>
//#include <GL/glut.h>
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);	// ������ ����� ���������� ����
//	glShadeModel(GL_SMOOTH);
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
//	triangle();
//
//	glFlush();	//�簢���� ȭ�鿡 �׸�
//}
//
//void reshape(int new_w, int new_h)
//{
//	float WidthFactor = (float) new_w / 300.0;
//	float HeightFactor = (float) new_h / 300.0;
//	glViewport(0, 0, new_w, new_h);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	// Without Reshape recalculation
//	//gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//	gluOrtho2D(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor);
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);	// GLUT ���¸� �ʱ�ȭ
//	// ���÷��̸������ ����: Single buffer & RGBA color ��� ����
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// â�� ũ��� ��ġ ����
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(100, 100);
//
//	glutCreateWindow(argv[0]);	// ������ ����
//	init();
//
//	// �ʿ��� �ݹ��Լ� ���
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);	// Reshape callback function ���
//	glutMainLoop();	// �̺�Ʈ ó������ ����
//	return 0;
//}