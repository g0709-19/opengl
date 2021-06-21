//#include <stdlib.h>
//#include <GL/glut.h>
//
//void display(void)
//{
//	glColor3f(1.0, 1.0, 1.0);	// 흰색으로 설정
//
//	// 사각형의 좌표 입력
//	glBegin(GL_LINE_LOOP);
//		glVertex3f(0.25, 0.25, 0.0);
//		glVertex3f(0.75, 0.25, 0.0);
//		glVertex3f(0.75, 0.75, 0.0);
//		glVertex3f(0.25, 0.75, 0.0);
//	glEnd();
//
//	glFlush();	//사각형을 화면에 그림
//}
//
//void init(void)
//{
//	// 리사이징 시 검은색으로 초기화 되네
//	glClearColor(0.0, 0.0, 0.0, 0.0);	// 윈도우 배경을 검은색으로 설정
//	glClear(GL_COLOR_BUFFER_BIT);	// 색상 버퍼를 지움. 지우면 색상 표시 안됨
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();	// 단위 행렬
//
//	// 직교 투영: left, right, bottom, top, near, far
//	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);	// GLUT 상태를 초기화
//	// 디스플레이모드형식 선택: Single buffer & RGBA color 모드 선택
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// 창의 크기와 위치 설정
//	glutInitWindowSize(250, 250);
//	glutInitWindowPosition(100, 100);
//
//	glutCreateWindow("01 사각형 그리기");	// 윈도우 생성
//	init();
//
//	// 필요한 콜백함수 등록
//	glutDisplayFunc(display);
//	glutMainLoop();	// 이벤트 처리엔진 시작
//	return 0;
//}