/*
	7-3 Moving Lightning 1 실습
*/

#include <stdio.h>
#include <gl/glut.h>
#include <gl/glu.h>
#include <gl/gl.h>

GLfloat position[] = {0.0, 5.0, 0.0, 1.0};	// 조명 위치 변경 변수

void init();
void display();
void reshape(int, int);
void mouse(int, int, int, int);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lightning Example");

	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}

void init(void)
{
	GLfloat light_ambient[] = {0.1, 0.1, 0.1, 1.0};
	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	// 감쇠율
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.001);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.004);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 조명 이동 적용
	glPushMatrix();
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	// 조명의 위치를 Cube로 출력
	glTranslated(position[0], position[1], position[2]);
	glDisable(GL_LIGHTING);	// Cube 의 색 표현을 위해 조명 제거
	glColor3f(0.0, 1.0, 1.0);
	glutWireCube(0.5);

	glEnable(GL_LIGHTING);
	glPopMatrix();

	glutSolidSphere(1, 50, 50);
	glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w, 5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
	switch(button) {
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{
			position[1] -= 0.1;
			printf("Light Position: (%.2lf, %.2lf, %.2lf)\n", position[0], position[1], position[2]);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{
			position[1] += 0.1;
			printf("Light Position: (%.2lf, %.2lf, %.2lf)\n", position[0], position[1], position[2]);
		}
		break;
	default:
		break;
	}
	glutPostRedisplay();
}