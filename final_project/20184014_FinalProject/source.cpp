#include <iostream>
#include <vector>
#include "model.h"
#include "tool.h"
#include "lodepng.h"

#include <GL/glut.h>

using namespace std;

// ȭ�� ǥ�ø� ���� �⺻ �Լ�
void init();
void initLight();
void initTexture();
void display();
void reshape(int width, int height);

// �� Ŭ����
Model model;

// �ؽ���
GLuint textureID[16];
void initTexture(GLuint* texture, char* path);

// �׸���
void drawCross();
void drawGround();
bool light = true;
bool color = true;
bool texture = true;

// Ű �Է�
void handleSpecialKey(int key, int x, int y);
void handleMenu(int index);
void zoomIn();
void zoomOut();
void rotateLeft();
void rotateRight();

// ����
GLfloat light_position[] = {10.0, 10.0, 10.0, 1.0};

// ī�޶� ȸ��
float rotateX = 0.0;
float radius = 25.0;

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(810, 810);
    glutCreateWindow("Final project");

	init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

	glutSpecialFunc(handleSpecialKey);

	GLint menu;
	menu = glutCreateMenu(handleMenu);
	glutAddMenuEntry("Light", 0);
	glutAddMenuEntry("Color", 1);
	glutAddMenuEntry("Texture", 2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
	return 0;
}

void init()
{
	model.loadModelWithObj("kirby.obj");

	glDepthFunc(GL_LESS);	// Depth Buffer Setup
    glEnable(GL_DEPTH_TEST);// Enables Depth Testing

    glClearColor(0.21, 0.21, 0.21, 0.0); // ��� ȸ������

	glEnable(GL_SMOOTH);

	initLight();

	cout << "�ؽ�ó �̹����� �ҷ��ɴϴ�\n";
	initTexture(&textureID[0], "behindhighlight.png");
	initTexture(&textureID[1], "foot.png");
	initTexture(&textureID[2], "browneye.png");
	initTexture(&textureID[3], "eyehighlight.png");
	initTexture(&textureID[4], "body.png");
	initTexture(&textureID[5], "hongjo.png");
	initTexture(&textureID[6], "grass.png");
	cout << "�̹����� �ҷ��Խ��ϴ�\n";
}

void initLight()
{
	GLfloat light_ambient[] = {1.0, 1.0, 1.0, 1.0};	// �ֺ���
	GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};	// Ȯ�걤
	GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};// ��鱤

	// ����
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

	// ����(������ ����ġ�� �����)
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.001);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0005);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void initTexture(GLuint* texture, char* path) {
	vector<unsigned char> image;
	unsigned width, height;
	unsigned error = lodepng::decode(image, width, height, path);

	if (!error)
		cout << "error " << error << ": " << lodepng_error_text(error) << '\n';
	
	size_t u2 = 1; while (u2 < width) u2 *= 2;
	size_t v2 = 1; while (v2 < height) v2 *= 2;

	glGenTextures(1, texture);
	glBindTexture(GL_TEXTURE_2D, *texture);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glEnable(GL_TEXTURE_2D);
}

void display() 
{
	/*
		�� ��Ʈ ��ġ
		3 4
		1 2
	*/
	int viewport_pos[16] = {
		0, 0, 400, 400,		// 1
		410, 0, 400, 400,	// 2
		0, 410, 400, 400,	// 3
		410, 410, 400, 400	// 4
	};

	// �� �� ��Ʈ�� ī�޶� ����
	float camera_pos[8] = {
		0.0, 90.0,	// 1 Front
		25.0, 25.0,	// 2 Random
		0.0, 0.0,	// 3 Top
		90.0, 90.0,	// 4 Side
	};

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ���� ����, ���� ���� û��

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// ���� ��� ���� Ȯ��
	if (light) glEnable(GL_LIGHTING);
	else glDisable(GL_LIGHTING);

	// �ؽ��� ��� ���� Ȯ��
	if (texture) glEnable(GL_TEXTURE_2D);
	else glDisable(GL_TEXTURE_2D);

	// 4���� �� ��Ʈ�� �� ȭ���� �׸�
	for (int i=0; i<4; ++i) {
		glPushMatrix();

		// ������ ������ ī�޶� ����, �� ��Ʈ ����
		Rotate temp(camera_pos[i*2] + rotateX, camera_pos[i*2+1], radius);
		temp.LookAt();
		glViewport(viewport_pos[i*4], viewport_pos[i*4+1], viewport_pos[i*4+2], viewport_pos[i*4+3]);

		// ����
		glPushMatrix();
		if (color)	// ���� ��� ���� Ȯ��
		{
			GLfloat mat_ambient[] = { 0.97, 0.94, 0.71 };
			GLfloat mat_diffuse[] = { 0.97, 0.94, 0.71 };
			GLfloat mat_specular[] = { 0.5, 0.5, 0.5 };
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
		}
		glBindTexture(GL_TEXTURE_2D, textureID[6]);
		drawGround();
		glPopMatrix();

		// ����(�ش� �ڵ� ��ü�� �������μ��� ������ ������ ��ġ Ȯ���� ���� ������)
		if (light)
		{
			glDisable(GL_LIGHTING);
			glPushMatrix();
			glColor3f(0.0, 0.0, 1.0);
			glTranslated(light_position[0], light_position[1], light_position[2]);
			glutWireCube(2.0);
			glPopMatrix();
			glEnable(GL_LIGHTING);
		}

		// ��
		glTranslatef(0, 6, 0);	// ���� ���� ��ġ�ϱ� ���� �̵�
			model.drawModel(textureID, color, texture);
		glPopMatrix();
	}
	// ����
	drawCross();

    glutSwapBuffers(); //swap the buffers
}

void reshape (int w, int h) 
{
    glViewport (0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode (GL_PROJECTION); 

    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1 , 100000.0);
    glMatrixMode (GL_MODELVIEW);
}

// ����
void drawCross()
{
	glDisable(GL_LIGHTING);
	glViewport(0, 0, 810, 810);
	glPushMatrix();
	gluLookAt(0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(10.0);
	glBegin(GL_LINES);
		glVertex3f(-50.0, 0.0, 0.0);
		glVertex3f(50.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, -50.0);
		glVertex3f(0.0, 0.0, 50.0);
	glEnd();
	glLineWidth(1.0);
	glPopMatrix();
	if (light)
		glEnable(GL_LIGHTING);
}

// ����
void drawGround()
{
	int size = 10.0;
    glPushMatrix();
	if (color)
		glColor3f(0.97, 0.94, 0.71);	// ������
    glBegin(GL_QUADS);
		glTexCoord3f(-size, 0.0, -size);
		glVertex3f(-size, 0.0, -size);

		glTexCoord3f(-size, 0.0, size);
		glVertex3f(-size, 0.0, size);

		glTexCoord3f(size, 0.0, size);
		glVertex3f(size, 0.0, size);

		glTexCoord3f(size, 0.0, -size);
		glVertex3f(size, 0.0, -size);
	glEnd();
    glPopMatrix();
}

// �˾� �޴�
void handleMenu(int index)
{
	switch (index) {
	case 0:
		light = !light;
		cout << "���� ��带 " << (light ? "�׽��ϴ�" : "�����ϴ�") << "\n";
		break;
	case 1:
		color = !color;
		cout << "���� ��带 " << (color ? "�׽��ϴ�" : "�����ϴ�") << "\n";
		break;
	case 2:
		texture = !texture;
		cout << "�ؽ��� ��带 " << (texture ? "�׽��ϴ�" : "�����ϴ�") << "\n";
		break;
	}
	glutPostRedisplay();
}

// ����Ű
void handleSpecialKey(int key, int x, int y)
{
	if(key == GLUT_KEY_UP)		zoomIn();
	if (key == GLUT_KEY_DOWN)	zoomOut();
	if (key == GLUT_KEY_LEFT)	rotateRight();
	if (key == GLUT_KEY_RIGHT)	rotateLeft();
	glutPostRedisplay();
}

void zoomIn()
{
	if (radius - 5.0 <= 0.0) {
		cout << "�� �̻� Ȯ���� �� �����ϴ�\n";
		return;
	}
	radius -= 5.0;
}

void zoomOut()
{
	radius += 5.0;
}

void rotateLeft()
{
	rotateX -= 5.0;
}

void rotateRight()
{
	rotateX += 5.0;
}