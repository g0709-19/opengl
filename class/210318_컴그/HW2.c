///*
//	������� �ﰢ�� �ΰ��� ����Ͽ� �������� �ϳ� �׸��ÿ�.
//	���콺 �̺�Ʈ�� �̿��Ͽ� ���� ���콺 Ŭ���ÿ� Ŭ����
//	��ġ�� ���� �̵��ϸ鼭 ���� ������ �����ϴ� ����
//	�׸��ÿ�. ��� ���� ��� �߰��Ǿ�� ��.
//	���콺 �̺�Ʈ�� �̿��Ͽ� ������ ���콺 Ŭ���ÿ� ���
//	���� ȸ���ϰ� �ѹ��� Ŭ���ϸ� ��۵Ǿ� ��� ���� �ݴ��
//	ȸ���ǵ��� ����ÿ�. ������ ���콺 Ŭ������ ��� ���
//	���콺 �̺�Ʈ�� �̿��Ͽ� �߰� ���콺 Ŭ���ÿ� ��� ����
//	���� �ٲ�� ����ÿ�.
//
//	�ۼ���: 2021�� 4�� 7��(��)
//	�й�: 20184014
//	�̸�: �̽���
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//// �� ������ ��� ����ü
//typedef struct Star {
//	float x, y;	// ��ǥ
//	int r, g, b;// ������
//} Star;
//
//typedef Star TYPE;	// ����Ʈ ��� ������ Ÿ���� Star�� ����
//
//// ����Ʈ ��� ����ü
//typedef struct ListNode {
//	TYPE data;
//	struct ListNode *link;
//} ListNode;
//
//ListNode *head;	// �� ������ ��� ����Ʈ
//
//static int LENGTH = 30;		// �ﰢ�� �� ���� ����
//static int WIDTH = 500;		// â ���� ����
//static int HEIGHT = 500;	// â ���� ����
//
//// ������(���� �������� �������� ���� �������� ����)
//int main_r = 0;
//int main_g = 0;
//int main_b = 0;
//
//// ȸ��
//GLfloat spin = 0.0;				// ȸ�� ����
//int spin_mode = 0;				// �ð����, �ð�ݴ����
//static float SPIN_SPEED = 1.0;	// ȸ�� �ӵ�
//
//// ����Ʈ �ʱ�ȭ
//void ListInit(ListNode **head) {
//	*head = (ListNode*)malloc(sizeof(ListNode));
//	(*head)->link = NULL;
//}
//
//// ����Ʈ ��� ����
//void ListInsert(ListNode *head, TYPE value) {
//	ListNode *node = head;
//	ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
//	new_node->data = value;
//	new_node->link = NULL;
//	// ����Ʈ�� ���� ã��
//	while (node->link)
//		node = node->link;
//	// ����Ʈ�� ���� ���ο� ��� ����
//	node->link = new_node;
//}
//
//// ����Ʈ ���� �Ҵ� ����
//void ListDestroy(ListNode **head) {
//	free(*head);
//}
//
//// ����Ʈ�� ����� ���� ��� �׸��� �Լ�
//void DrawStar() {
//	ListNode *node = head->link;
//	float gap = LENGTH/2.0; // �ﰢ�� �� ���� ������ ���� ���� ������ ����
//
//	// ����Ʈ�� ����� �� ��� �׸�
//	while (node) {
//		int r, g, b;	// ������ + ������ = ������. 255�� ���� �ʵ��� modular ����
//		r = (node->data.r + main_r) % 256;
//		g = (node->data.g + main_g) % 256;
//		b = (node->data.b + main_b) % 256;
//
//		glPushMatrix();	// �̵�, ȸ���� �ٸ� �𵨿� �������� ���ϵ��� ����
//
//		glColor3f((GLfloat)r/255, (GLfloat)g/255, (GLfloat)b/255);	// �� ����
//		glTranslatef(node->data.x, node->data.y, 0.0);				// ���ڸ� ȸ���� ���� �̵�
//		glRotatef(spin, 0.0, 0.0, 1.0);								// ȸ��
//
//		glBegin(GL_TRIANGLES);
//		// ���ﰢ��
//			glVertex3f(-gap, -gap, 0.0);
//			glVertex3f(gap, -gap, 0.0);
//			glVertex3f(0.0, gap, 0.0);
//		// ���ﰢ��
//			glVertex3f(-gap, gap-(gap*0.7), 0.0);
//			glVertex3f(gap, gap-(gap*0.7), 0.0);
//			glVertex3f(0.0, -gap-(gap*0.7), 0.0);
//		glEnd();
//
//		glPopMatrix();
//		node = node->link;
//	}
//}
//
//// ����Ʈ�� ����� ���� ������ �����ϴ� ��� ���� �׸��� �Լ�
//void DrawLine() {
//	ListNode *node = head->link;
//	glPushMatrix();
//	glBegin(GL_LINE_STRIP);	// ��� ���� ������ �����ϴ� ����(���� ��, �� ���� �̾����� ����)
//	while (node) {
//		glColor3f((GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0);	// �� ����
//		glVertex3f(node->data.x, node->data.y, 0.0);			// ��� ���� ������ ������ ����
//		node = node->link;
//	}
//	glEnd();
//	glPopMatrix();
//}
//
//// ��, �� �׸��� �Լ�
//void Display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	DrawStar();
//	DrawLine();
//	glutSwapBuffers();
//}
//
//// �� ȸ�� �Լ�
//void SpinStar(void)
//{
//	if (spin_mode)
//		spin = spin + SPIN_SPEED;
//	else
//		spin = spin - SPIN_SPEED;
//	if(spin > 360.0 || spin < -360.0) spin = 0;
//	glutPostRedisplay();
//}
//
//// ȸ�� ���� ���� �Լ�
//void ToggleSpin()
//{
//	spin_mode = spin_mode ? 0 : 1;
//	if (spin_mode)
//		printf("�ð� �������� ȸ��\n");
//	else
//		printf("�ð� �ݴ�������� ȸ��\n");
//}
//
//// ���� �ʱ�ȭ �Լ�
//void Init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0); // ���� �������� ����
//	glShadeModel(GL_FLAT);
//}
//
//// Reshape �ݹ� �Լ�
//void Reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(0.0, WIDTH, HEIGHT, 0.0, -1.0, 1.0);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//// �� ���� �߰� �Լ�
//void AddStarTo(int x, int y)
//{
//	Star star;
//	int r, g, b;	// ���� �߰��� �� �� �� ������ ���� ���� ������ ��
//	r = rand() % 256; g = rand() % 256; b = rand() % 256;
//	star.x = x; star.y = y;				// ��ǥ ����
//	star.r = r; star.g = g; star.b = b;	// ���� ����
//	ListInsert(head, star);
//	printf("�� �߰� ��ǥ: (%d, %d) ������: #%02x%02x%02x\n", x, y, r, g, b);
//	glutPostRedisplay();
//}
//
//// ���� �� ���� �Լ�
//void ChooseRandomColor()
//{
//	main_r = rand() % 256;
//	main_g = rand() % 256;
//	main_b = rand() % 256;
//	printf("�� ���� #%02x%02x%02x\n", main_r, main_g, main_b);
//	glutPostRedisplay();
//}
//
//// ���콺 �Է� �ݹ� �Լ�
//void Mouse(int button, int state, int x, int y)
//{
//	switch (button)
//	{
//		case GLUT_LEFT_BUTTON:
//			if (state == GLUT_DOWN) AddStarTo(x, y);
//			break;
//		case GLUT_RIGHT_BUTTON:
//			if (state == GLUT_DOWN) { glutIdleFunc(SpinStar); ToggleSpin(); }
//			break;
//		case GLUT_MIDDLE_BUTTON:
//			if (state == GLUT_DOWN) ChooseRandomColor();
//			break;
//		default:
//			break;
//	}
//}
//
//int main(int argc, char** argv)
//{
//	ListInit(&head);
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // ���� ���۸�
//	glutInitWindowSize(WIDTH, HEIGHT);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("20184014_HW2");
//	Init();
//	glutDisplayFunc(Display);
//	glutReshapeFunc(Reshape);
//	glutMouseFunc(Mouse);
//	glutMainLoop();
//	ListDestroy(&head);
//	return 0;
//}