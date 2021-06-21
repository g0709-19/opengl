///*
//	윈도우상에 삼각형 두개를 사용하여 작은별을 하나 그리시오.
//	마우스 이벤트를 이용하여 왼쪽 마우스 클릭시에 클릭된
//	위치로 별이 이동하면서 별의 중점을 연결하는 선을
//	그리시오. 모든 별이 계속 추가되어야 함.
//	마우스 이벤트를 이용하여 오른쪽 마우스 클릭시에 모든
//	별이 회전하고 한번더 클릭하면 토글되어 모든 별이 반대로
//	회전되도록 만드시오. 오른쪽 마우스 클릭마다 계속 토글
//	마우스 이벤트를 이용하여 중간 마우스 클릭시에 모든 별의
//	색이 바뀌도록 만드시오.
//
//	작성일: 2021년 4월 7일(수)
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
//// 별 정보를 담는 구조체
//typedef struct Star {
//	float x, y;	// 좌표
//	int r, g, b;// 고유색
//} Star;
//
//typedef Star TYPE;	// 리스트 노드 데이터 타입을 Star로 지정
//
//// 리스트 노드 구조체
//typedef struct ListNode {
//	TYPE data;
//	struct ListNode *link;
//} ListNode;
//
//ListNode *head;	// 별 정보를 담는 리스트
//
//static int LENGTH = 30;		// 삼각형 한 변의 길이
//static int WIDTH = 500;		// 창 가로 길이
//static int HEIGHT = 500;	// 창 세로 길이
//
//// 랜덤색(별의 고유색에 랜덤색을 더해 최종색을 구함)
//int main_r = 0;
//int main_g = 0;
//int main_b = 0;
//
//// 회전
//GLfloat spin = 0.0;				// 회전 각도
//int spin_mode = 0;				// 시계방향, 시계반대방향
//static float SPIN_SPEED = 1.0;	// 회전 속도
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
//	free(*head);
//}
//
//// 리스트에 저장된 별을 모두 그리는 함수
//void DrawStar() {
//	ListNode *node = head->link;
//	float gap = LENGTH/2.0; // 삼각형 한 변을 반으로 나눠 양쪽 간격을 구함
//
//	// 리스트에 저장된 별 모두 그림
//	while (node) {
//		int r, g, b;	// 고유색 + 랜덤색 = 최종색. 255를 넘지 않도록 modular 연산
//		r = (node->data.r + main_r) % 256;
//		g = (node->data.g + main_g) % 256;
//		b = (node->data.b + main_b) % 256;
//
//		glPushMatrix();	// 이동, 회전이 다른 모델에 관여하지 못하도록 관리
//
//		glColor3f((GLfloat)r/255, (GLfloat)g/255, (GLfloat)b/255);	// 색 지정
//		glTranslatef(node->data.x, node->data.y, 0.0);				// 제자리 회전을 위한 이동
//		glRotatef(spin, 0.0, 0.0, 1.0);								// 회전
//
//		glBegin(GL_TRIANGLES);
//		// 정삼각형
//			glVertex3f(-gap, -gap, 0.0);
//			glVertex3f(gap, -gap, 0.0);
//			glVertex3f(0.0, gap, 0.0);
//		// 역삼각형
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
//// 리스트에 저장된 별의 중점을 연결하는 모든 선을 그리는 함수
//void DrawLine() {
//	ListNode *node = head->link;
//	glPushMatrix();
//	glBegin(GL_LINE_STRIP);	// 모든 별의 중점을 연결하는 형태(시작 별, 끝 별은 이어지지 않음)
//	while (node) {
//		glColor3f((GLfloat)1.0, (GLfloat)1.0, (GLfloat)1.0);	// 색 지정
//		glVertex3f(node->data.x, node->data.y, 0.0);			// 모든 별의 중점에 정점을 찍음
//		node = node->link;
//	}
//	glEnd();
//	glPopMatrix();
//}
//
//// 별, 선 그리는 함수
//void Display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	DrawStar();
//	DrawLine();
//	glutSwapBuffers();
//}
//
//// 별 회전 함수
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
//// 회전 방향 변경 함수
//void ToggleSpin()
//{
//	spin_mode = spin_mode ? 0 : 1;
//	if (spin_mode)
//		printf("시계 방향으로 회전\n");
//	else
//		printf("시계 반대방향으로 회전\n");
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
//// 별 중점 추가 함수
//void AddStarTo(int x, int y)
//{
//	Star star;
//	int r, g, b;	// 별을 추가할 때 그 별 고유의 랜덤 색을 가지게 함
//	r = rand() % 256; g = rand() % 256; b = rand() % 256;
//	star.x = x; star.y = y;				// 좌표 저장
//	star.r = r; star.g = g; star.b = b;	// 색상 저장
//	ListInsert(head, star);
//	printf("별 추가 좌표: (%d, %d) 고유색: #%02x%02x%02x\n", x, y, r, g, b);
//	glutPostRedisplay();
//}
//
//// 랜덤 색 선택 함수
//void ChooseRandomColor()
//{
//	main_r = rand() % 256;
//	main_g = rand() % 256;
//	main_b = rand() % 256;
//	printf("색 변경 #%02x%02x%02x\n", main_r, main_g, main_b);
//	glutPostRedisplay();
//}
//
//// 마우스 입력 콜백 함수
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
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // 더블 버퍼링
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