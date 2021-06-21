//#include <stdio.h>
//#include <stdlib.h>
//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <GL/gl.h>
//
//static GLfloat spin = 0.0;
//
//void display(void)
//{
//	int r, g, b;
//	r = rand() % 256;
//	g = rand() % 256;
//	b = rand() % 256;
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glPushMatrix(); // ?
//	glRotatef(spin, 0.0, 0.0, 1.0);
//	glColor3f((GLfloat)r/255, (GLfloat)g/255, (GLfloat)b/255);
//	glRectf(-25.0, -25.0, 25.0, 25.0);
//	glPopMatrix();
//
//	glutSwapBuffers();
//	//glFlush();
//}
//
//void spinDisplay(void)
//{
//	spin = spin + 0.5;
//	if(spin > 360.0) spin = spin - 360.0;
//	glutPostRedisplay();
//}
//
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0); // background
//	glShadeModel(GL_FLAT); // flat shading
//}
//
//void reshape(int w, int h)
//{
//	glViewport(0, 0, (GLsizei) w, (GLsizei) h); // w, h 무슨 값이지
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity(); // ?
//	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
//	glMatrixMode(GL_MODELVIEW); // 모델뷰는 뭐지
//	glLoadIdentity(); // ?
//}
//
//void mouse(int button, int state, int x, int y)
//{
//	switch (button)
//	{
//		case GLUT_LEFT_BUTTON:
//			if (state == GLUT_DOWN) glutIdleFunc(spinDisplay);
//			break;
//		case GLUT_RIGHT_BUTTON:
//			if (state == GLUT_DOWN) glutIdleFunc(NULL);
//			break;
//		default:
//			break;
//	}
//}
//
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // double buffering
//	// 싱글버퍼 쓰면 플리커링 뜨나 => 그렇다. 마우스 입력도 안 먹고 회전 속도도 엄청 빨라짐.
//	glutInitWindowSize(250, 250);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("02_5 사각형 회전");
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//	glutMouseFunc(mouse);
//	glutMainLoop();
//	return 0;
//}