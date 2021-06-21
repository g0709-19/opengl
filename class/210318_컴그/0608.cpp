//#include <iostream>
//#include <GL/glut.h>
//#include <vector>
//#include "lodepng.h"
//
//using namespace std;
//
//float rotation = 0.0f;
//float angularVelocity = 1.5f;
//GLuint textureID[2];
//vector<unsigned char> image2;
//void loadTexture(GLuint* texture, char* path);
//
//void render()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_TEXTURE_2D);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
//	glViewport(0, 0, 500, 500);
//
//	glPushMatrix();
//		glRotatef(rotation, 0.0f, 1.0f, 0.0f);
//
//		glBindTexture(GL_TEXTURE_2D, textureID[0]);
//		glBegin(GL_TRIANGLES);
//			glTexCoord2f(0.0f, 1.0f);	glVertex3f(-50.0f, -50.0f, 0.0f);
//			glTexCoord2f(0.5f, 0.0f);	glVertex3f(0.0f, 50.0f, 0.0f);
//			glTexCoord2f(1.0f, 1.0f);	glVertex3f(50.0f, -50.0f, 0.0f);
//		glEnd();
//
//		glBindTexture(GL_TEXTURE_2D, textureID[1]);
//		glBegin(GL_TRIANGLES);
//			glTexCoord2f(0.5f, 0.0f);	glVertex3f(0.0f, 50.0f, 0.0f);
//			glTexCoord2f(0.0f, 1.0f);	glVertex3f(-50.0f, -50.0f, 0.0f);
//			glTexCoord2f(1.0f, 1.0f);	glVertex3f(50.0f, -50.0f, 0.0f);
//		glEnd();
//	glPopMatrix();
//
//	glutSwapBuffers();
//}
//
//void reshape(int w, int h)
//{
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//	glViewport(0, 0, 500, 500);
//	glOrtho(-100.0f, 100.0f, -100.0f, 100.0f, -100.0f, 100.0f);
//	glutPostRedisplay();
//}
//
//void rotate(int value)
//{
//	rotation += angularVelocity;
//	glutTimerFunc(10, rotate, 0);
//	glutPostRedisplay();
//}
//
//void swap(unsigned char *a, unsigned char *b)
//{
//	const unsigned char temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//void loadTexture(GLuint* texture, char* path) {
//	vector<unsigned char> image;
//	unsigned width, height;
//	unsigned error = lodepng::decode(image, width, height, path);
//
//	if (!error)
//		cout << "error " << error << ": " << lodepng_error_text(error) << '\n';
//	size_t u2 = 1; while (u2 < width) u2 *= 2;
//	size_t v2 = 1; while (v2 < height) v2 *= 2;
//	image2 = vector<unsigned char>(u2 * v2 * 4);
//	for (size_t y = 0; y < height; ++y)
//		for (size_t x = 0; x < width; ++x)
//			for (size_t c = 0; c < 4; ++c)
//				image2[4 * u2 * y + 4 * x + c] = image[4 * width * y + 4 * x + c];
//	glGenTextures(1, texture);
//	glBindTexture(GL_TEXTURE_2D, *texture);
//	glTexImage2D(GL_TEXTURE_2D, 0, 4, u2, v2, 0, GL_RGBA, GL_UNSIGNED_BYTE, &image2[0]);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//}
//
//void initialize()
//{
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//	loadTexture(&textureID[0], "FRONT.png");
//	loadTexture(&textureID[1], "BACK.png");
//}
//
//int main(int argc, char ** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//	
//	glClearColor(0, 0, 0, 0);
//
//	glutInitWindowPosition(50, 50);
//	glutInitWindowSize(500, 500);
//	glutCreateWindow("GLUT Texture Demo");
//
//	initialize();
//
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(render);
//	glutTimerFunc(10, rotate, 0);
//	glutMainLoop();
//	return 1;
//}