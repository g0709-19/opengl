///*
//	Interactive하게 폴리곤을 그리는 프로그램을 작성하라:
//	사용자가 매번 왼쪽 마우스 버튼을 누를 때마다 점들이 추가
//	되어야 하고, 오른쪽 마우스 버튼을 누르면 하나의 색으로
//	칠해진 폴리곤을 만든다. 이때 매번 마우스 클릭으로 점들이
//	추가될 때마다 점들이 보여야 하고, 점의 위에는 해당 숫자가
//	나와야 한다. 처음 점이 0부터 시작해서 순서대로 증가한다.
//	마지막 점으로부터 현재 점까지의 라인은 rubber band line으로
//	표현 되어야 한다. motion callback function, glutPostRedisplay
//	function을 활용할 것
//	물체 전체를 드래그 하면 마우스의 이동에 따라서 물체가
//	회전하면서 이동되도록 구현하고 Middle 버튼을 누르면
//	초기화되어야 함
//
//	작성일: 2021년 4월 17일(토)
//	학번: 20184014
//	이름: 이승준
//*/
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//#define MAX_VERTEX	5	// 정점 인덱스 표기 자리수
//
//#define LENGTH		30	// 삼각형 한 변의 길이
//#define WIDTH		500	// 창 가로 길이
//#define HEIGHT		500	// 창 세로 길이
//
//#define min(a, b) (((a) < (b)) ? (a) : (b))
//#define max(a, b) (((a) > (b)) ? (a) : (b))
//
//// 정점 정보를 담는 구조체
//typedef struct Vertex {
//	float x, y;	// 좌표
//} Vertex;
//
//typedef Vertex TYPE;	// 리스트 노드 데이터 타입을 Vertex로 지정
//
//// 리스트 노드 구조체
//typedef struct ListNode {
//	TYPE data;
//	struct ListNode *link;
//} ListNode;
//
//ListNode *head;		// 정점 정보를 담는 리스트
//
//// 마우스 위치
//int mouse_x = 0;
//int mouse_y = 0;
//
//int polygon = 0;	// 폴리곤 여부
//
//// 드래그
//int drag = 0;		// 드래그 여부
//int drag_start_x = 0.0;
//int drag_start_y = 0.0;
//int drag_end_x = 0.0;
//int drag_end_y = 0.0;
//int following = 0;	// 마우스 따라오는 여부
//
//// 오브젝트 고점, 저점
//int left = 0;
//int right = 0;
//int top = 0;
//int bottom = 0;
//
//// 회전
//GLfloat angle = 0.0;			// 회전 각도
//float ROTATE_SPEED = 1.0;		// 회전 속도
//
//// 리스트 초기화
//void ListInit(ListNode **head) {
//	*head = (ListNode*)malloc(sizeof(ListNode));
//	(*head)->link = NULL;
//}
//
//// 리스트 노드 삽입
//void ListInsert(ListNode *head, TYPE value) {
//	ListNode *node = head;
//	ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
//	new_node->data = value;
//	new_node->link = NULL;
//	// 리스트의 끝을 찾음
//	while (node->link)
//		node = node->link;
//	// 리스트의 끝에 새로운 노드 삽입
//	node->link = new_node;
//}
//
//// 리스트 동적 할당 해제
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
//// 리스트에 저장된 정점을 연결하는 모든 선을 그리는 함수
//void DrawLine() {
//	ListNode *node = head->link;
//	glColor3f((GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0);	// 색 지정
//
//	glBegin(GL_LINE_STRIP);	// 모든 정점을 연결하는 형태
//	while (node) {
//		glVertex3f(node->data.x, node->data.y, 0.0);			// 모든 정점을 찍음
//		node = node->link;
//	}
//	if (polygon)
//		glVertex3f(head->link->data.x, head->link->data.y, 0.0);	// 선 고정
//	else
//		glVertex3f(mouse_x, mouse_y, 0.0);	// Rubber band
//	glEnd();
//}
//
//void DrawPoint() {
//	ListNode *node = head->link;
//	if (polygon) // 폴리곤이면 정점 파란색
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
//// 정점 번호 출력
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
//		while (*sp) { // 인덱스를 문자열로 바꿔 한 문자씩 출력
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
//	glColor3f(0.5, 0.5, 0.5);	// 회색
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
//	// 오브젝트 중점 계산
//	float x = (right-left)/2.0;
//	float y = (bottom-top)/2.0;
//
//	glTranslatef(mouse_x, mouse_y, 0.0);// 4. 마우스 좌표로 오브젝트 이동
//	glRotatef(angle, 0.0, 0.0, 1.0);	// 3. angle 만큼 오브젝트 회전
//	glTranslatef(-x, -y, 0.0);			// 2. 원점에 오브젝트의 중심이 놓이도록 이동
//	glTranslatef(-left, -top, 0.0);		// 1. 오브젝트의 좌측 상단을 원점으로 이동
//}
//
//// 전체 그리는 함수
//void Display(void)
//{
//	glLoadIdentity();	// 행렬 초기화
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
//// 설정 초기화 함수
//void Init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0); // 배경색 검정으로 지정
//	glShadeModel(GL_FLAT);
//}
//
//// Reshape 콜백 함수
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
//// 마우스 위치 저장 함수
//void SaveMousePosition(int x, int y) {
//	mouse_x = x;
//	mouse_y = y;
//	if (!polygon)	// 폴리곤이면 SpinAngle 함수에서 그림
//		glutPostRedisplay();
//}
//
//// 회전 함수
//void SpinAngle() {
//	angle += ROTATE_SPEED;
//	if (angle > 360.0) angle -= 360.0;
//	glutPostRedisplay();
//}
//
//// 정점 추가 함수
//void AddVertexTo(int x, int y)
//{
//	Vertex vertex;
//	vertex.x = x; vertex.y = y;				// 좌표 저장
//
//	left = left == 0 ? x : min(left, x);
//	right = max(right, x);
//	top = top == 0 ? y : min(top, y);
//	bottom = max(bottom, y);
//
//	printf("left: %d, right: %d, top: %d, bottom: %d\n", left, right, top, bottom);
//
//	ListInsert(head, vertex);
//	printf("정점 추가 좌표: (%d, %d)\n", x, y);
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
//// 정점 입력 다시 가능하도록 초기화하는 함수
//void Reset()
//{
//	ListDestroy(&head);
//	ListInit(&head);
//	TurnOffPolygon();
//	left = right = bottom = top = 0;
//	angle = 0.0;
//	following = 0;
//	glutIdleFunc(NULL);
//	printf("초기화 성공\n");
//}
//
//void TurnOnFollowing() {
//	glutIdleFunc(SpinAngle);
//	following = 1;
//}
//
//// 마우스 입력 콜백 함수
//void Mouse(int button, int state, int x, int y)
//{
//	switch (button)
//	{
//		case GLUT_LEFT_BUTTON:
//			if (polygon) {
//				if (following) break;
//				// 드래그
//				if (state == GLUT_DOWN) {
//					drag = 1;
//					drag_start_x = x;
//					drag_start_y = y;
//					printf("%d %d 드래그 시작\n", drag_start_x, drag_start_y);
//				} else if (state == GLUT_UP && drag) {
//					drag = 0;
//					drag_end_x = x;
//					drag_end_y = y;
//					printf("%d %d 드래그 종료\n", drag_end_x, drag_end_y);
//					if (min(drag_start_x, drag_end_x) <= left && max(drag_start_x, drag_end_x) >= right
//						&& min(drag_start_y, drag_end_y) <= top && max(drag_start_y, drag_end_y) >= bottom) {
//						printf("오브젝트 선택됨\n");
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
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 더블 버퍼링
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