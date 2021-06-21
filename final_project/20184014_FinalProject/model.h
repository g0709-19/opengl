#pragma once
#include <vector>
#include <GL/glut.h>

using namespace std;

// 3���� ��ǥ�� ��Ÿ���� Ŭ����
class Point3f {
public:
	float x, y, z;
	float* toArray();
};

class Point3i {
public:
	int v1, v2, v3;
};

// ����, �ؽ�ó, ���� 3���� ���� �� �ϳ��� Triangle ���� ����
class Face {
public:
	Point3i p1;
	Point3i p2;
	Point3i p3;
};

// 3���� ��ǥ�� ��� ���͸� �������� ���� �̸� ����
typedef vector<Point3f> VerticeGroup;
typedef vector<Point3f> NormalGroup;
typedef vector<Point3f> TextureGroup;

// �� ������ ��� ���͸� �������� ���� �̸� ����
typedef vector<Face> FaceGroup;

class Object {
public:
	VerticeGroup vertices;	// ����
	NormalGroup normals;	// ���� ����
	TextureGroup textures;	// �ؽ���
	FaceGroup faces;		// ��
	float color[3];			// ����
	GLuint textureID;		// �ؽ���
};

// ������Ʈ ������ ��� ���͸� �������� ���� �̸� ����
typedef vector<Object> ObjectGroup;

// ���� ��� Ŭ����
class Model {
public:
	ObjectGroup objects;
	void loadModelWithObj(string filePath);
	void drawModel(GLuint *textureID, bool color, bool texture);
};