///*
//	Interactive�ϰ� �������� �׸��� ���α׷��� �ۼ��϶�:
//	����ڰ� �Ź� ���� ���콺 ��ư�� ���� ������ ������ �߰�
//	�Ǿ�� �ϰ�, ������ ���콺 ��ư�� ������ �ϳ��� ������
//	ĥ���� �������� �����. �̶� �Ź� ���콺 Ŭ������ ������
//	�߰��� ������ ������ ������ �ϰ�, ���� ������ �ش� ���ڰ�
//	���;� �Ѵ�. ó�� ���� 0���� �����ؼ� ������� �����Ѵ�.
//	������ �����κ��� ���� �������� ������ rubber band line����
//	ǥ�� �Ǿ�� �Ѵ�. motion callback function, glutPostRedisplay
//	function�� Ȱ���� ��
//	��ü ��ü�� �巡�� �ϸ� ���콺�� �̵��� ���� ��ü��
//	ȸ���ϸ鼭 �̵��ǵ��� �����ϰ� Middle ��ư�� ������
//	�ʱ�ȭ�Ǿ�� ��
//
//	�ۼ���: 2021�� 4�� 17��(��)
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
//#define MAX_VERTEX	5	// ���� �ε��� ǥ�� �ڸ���
//
//#define LENGTH		30	// �ﰢ�� �� ���� ����
//#define WIDTH		500	// â ���� ����
//#define HEIGHT		500	// â ���� ����
//
//#define min(a, b) (((a) < (b)) ? (a) : (b))
//#define max(a, b) (((a) > (b)) ? (a) : (b))
//
//// ���� ������ ��� ����ü
//typedef struct Vertex {
//	float x, y;	// ��ǥ
//} Vertex;
//
//typedef Vertex TYPE;	// ����Ʈ ��� ������ Ÿ���� Vertex�� ����
//
//// ����Ʈ ��� ����ü
//typedef struct ListNode {
//	TYPE data;
//	struct ListNode *link;
//} ListNode;
//
//ListNode *head;		// ���� ������ ��� ����Ʈ
//
//// ���콺 ��ġ
//int mouse_x = 0;
//int mouse_y = 0;
//
//int polygon = 0;	// ������ ����
//
//// �巡��
//int drag = 0;		// �巡�� ����
//int drag_start_x = 0.0;
//int drag_start_y = 0.0;
//int drag_end_x = 0.0;
//int drag_end_y = 0.0;
//int following = 0;	// ���콺 ������� ����
//
//// ������Ʈ ����, ����
//int left = 0;
//int right = 0;
//int top = 0;
//int bottom = 0;
//
//// ȸ��
//GLfloat angle = 0.0;			// ȸ�� ����
//float ROTATE_SPEED = 1.0;		// ȸ�� �ӵ�
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
//	ListNode *node = *head;
//	ListNode *deleted;
//	while (node) {
//		deleted = node;
//		node = node->link;
//		free(deleted);
//	}
//}
//
//// ����Ʈ�� ����� ������ �����ϴ� ��� ���� �׸��� �Լ�
//void DrawLine() {
//	ListNode *node = head->link;
//	glColor3f((GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0);	// �� ����
//
//	glBegin(GL_LINE_STRIP);	// ��� ������ �����ϴ� ����
//	while (node) {
//		glVertex3f(node->data.x, node->data.y, 0.0);			// ��� ������ ����
//		node = node->link;
//	}
//	if (polygon)
//		glVertex3f(head->link->data.x, head->link->data.y, 0.0);	// �� ����
//	else
//		glVertex3f(mouse_x, mouse_y, 0.0);	// Rubber band
//	glEnd();
//}
//
//void DrawPoint() {
//	ListNode *node = head->link;
//	if (polygon) // �������̸� ���� �Ķ���
//		glColor3f(0.0, 0.0, 1.0);
//	else
//		glColor3f(1.0, 0.0, 0.0);
//
//	glPointSize(10);
//	glBegin(GL_POINTS);
//	while (node) {
//		glVertex3f(node->data.x, node->data.y, 0.0);
//		node = node->link;
//	}
//	glEnd();
//}
//
//// ���� ��ȣ ���
//void DrawIndex()
//{
//	char s[MAX_VERTEX] = {0,};
//	int index = 0;
//	ListNode *node = head->link;
//
//	while (node) {
//		char *sp = s;
//		glRasterPos2f(node->data.x-5.0, node->data.y-7.0);
//		sprintf(s, "%d", index);
//		while (*sp) { // �ε����� ���ڿ��� �ٲ� �� ���ھ� ���
//			glutBitmapCharacter(GLUT_BITMAP_9_BY_15, *sp);
//			++sp;
//		}
//		node = node->link;
//		++index;
//	}
//}
//
//void DrawPolygon()
//{
//	ListNode *node = head->link;
//	glColor3f(0.5, 0.5, 0.5);	// ȸ��
//
//	glBegin(GL_POLYGON);
//	while (node) {
//		glVertex3f(node->data.x, node->data.y, 0.0);
//		node = node->link;
//	}
//	glEnd();
//}
//
//void MoveObject() {
//	// ������Ʈ ���� ���
//	float x = (right-left)/2.0;
//	float y = (bottom-top)/2.0;
//
//	glTranslatef(mouse_x, mouse_y, 0.0);// 4. ���콺 ��ǥ�� ������Ʈ �̵�
//	glRotatef(angle, 0.0, 0.0, 1.0);	// 3. angle ��ŭ ������Ʈ ȸ��
//	glTranslatef(-x, -y, 0.0);			// 2. ������ ������Ʈ�� �߽��� ���̵��� �̵�
//	glTranslatef(-left, -top, 0.0);		// 1. ������Ʈ�� ���� ����� �������� �̵�
//}
//
//// ��ü �׸��� �Լ�
//void Display(void)
//{
//	glLoadIdentity();	// ��� �ʱ�ȭ
//
//	glClear(GL_COLOR_BUFFER_BIT);
//	if (polygon) {
//		if (following) MoveObject();
//		DrawPolygon();
//	}
//	DrawLine();
//	DrawPoint();
//	DrawIndex();
//
//	glutSwapBuffers();
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
//// ���콺 ��ġ ���� �Լ�
//void SaveMousePosition(int x, int y) {
//	mouse_x = x;
//	mouse_y = y;
//	if (!polygon)	// �������̸� SpinAngle �Լ����� �׸�
//		glutPostRedisplay();
//}
//
//// ȸ�� �Լ�
//void SpinAngle() {
//	angle += ROTATE_SPEED;
//	if (angle > 360.0) angle -= 360.0;
//	glutPostRedisplay();
//}
//
//// ���� �߰� �Լ�
//void AddVertexTo(int x, int y)
//{
//	Vertex vertex;
//	vertex.x = x; vertex.y = y;				// ��ǥ ����
//
//	left = left == 0 ? x : min(left, x);
//	right = max(right, x);
//	top = top == 0 ? y : min(top, y);
//	bottom = max(bottom, y);
//
//	printf("left: %d, right: %d, top: %d, bottom: %d\n", left, right, top, bottom);
//
//	ListInsert(head, vertex);
//	printf("���� �߰� ��ǥ: (%d, %d)\n", x, y);
//	glutPostRedisplay();
//}
//
//void TurnOnPolygon()
//{
//	if (head->link == NULL) return;
//	polygon = 1;
//	glutPostRedisplay();
//}
//
//void TurnOffPolygon()
//{
//	polygon = 0;
//	glutPostRedisplay();
//}
//
//// ���� �Է� �ٽ� �����ϵ��� �ʱ�ȭ�ϴ� �Լ�
//void Reset()
//{
//	ListDestroy(&head);
//	ListInit(&head);
//	TurnOffPolygon();
//	left = right = bottom = top = 0;
//	angle = 0.0;
//	following = 0;
//	glutIdleFunc(NULL);
//	printf("�ʱ�ȭ ����\n");
//}
//
//void TurnOnFollowing() {
//	glutIdleFunc(SpinAngle);
//	following = 1;
//}
//
//// ���콺 �Է� �ݹ� �Լ�
//void Mouse(int button, int state, int x, int y)
//{
//	switch (button)
//	{
//		case GLUT_LEFT_BUTTON:
//			if (polygon) {
//				if (following) break;
//				// �巡��
//				if (state == GLUT_DOWN) {
//					drag = 1;
//					drag_start_x = x;
//					drag_start_y = y;
//					printf("%d %d �巡�� ����\n", drag_start_x, drag_start_y);
//				} else if (state == GLUT_UP && drag) {
//					drag = 0;
//					drag_end_x = x;
//					drag_end_y = y;
//					printf("%d %d �巡�� ����\n", drag_end_x, drag_end_y);
//					if (min(drag_start_x, drag_end_x) <= left && max(drag_start_x, drag_end_x) >= right
//						&& min(drag_start_y, drag_end_y) <= top && max(drag_start_y, drag_end_y) >= bottom) {
//						printf("������Ʈ ���õ�\n");
//						TurnOnFollowing();
//					}
//				}
//			} else if (state == GLUT_DOWN) AddVertexTo(x, y);
//			break;
//		case GLUT_RIGHT_BUTTON:
//			if (state == GLUT_DOWN && !polygon) TurnOnPolygon();
//			break;
//		case GLUT_MIDDLE_BUTTON:
//			if (state == GLUT_DOWN) Reset();
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
//	glutCreateWindow("20184014_MidTerm");
//	Init();
//	glutDisplayFunc(Display);
//	glutReshapeFunc(Reshape);
//	glutMouseFunc(Mouse);
//	glutPassiveMotionFunc(SaveMousePosition); 
//	glutMotionFunc(SaveMousePosition);
//	glutMainLoop();
//	ListDestroy(&head);
//	return 0;
//}