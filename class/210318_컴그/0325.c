//#include <stdlib.h>
//#include <GL/glut.h>
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);	// 윈도우 배경을 검은색으로 설정
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
//	glFlush();	//사각형을 화면에 그림
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
//	glutInit(&argc, argv);	// GLUT 상태를 초기화
//	// 디스플레이모드형식 선택: Single buffer & RGBA color 모드 선택
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// 창의 크기와 위치 설정
//	glutInitWindowSize(300, 300);
//	glutInitWindowPosition(100, 100);
//
//	glutCreateWindow(argv[0]);	// 윈도우 생성
//	init();
//
//	// 필요한 콜백함수 등록
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);	// Reshape callback function 등록
//	glutMainLoop();	// 이벤트 처리엔진 시작
//	return 0;
//}