#pragma once
#include <vector>
#include <GL/glut.h>

using namespace std;

// 3차원 좌표를 나타내는 클래스
class Point3f {
public:
	float x, y, z;
	float* toArray();
};

class Point3i {
public:
	int v1, v2, v3;
};

// 정점, 텍스처, 법선 3개의 점이 모여 하나의 Triangle 면을 만듦
class Face {
public:
	Point3i p1;
	Point3i p2;
	Point3i p3;
};

// 3차원 좌표를 담는 벡터를 가독성을 위해 이름 변경
typedef vector<Point3f> VerticeGroup;
typedef vector<Point3f> NormalGroup;
typedef vector<Point3f> TextureGroup;

// 면 정보를 담는 벡터를 가독성을 위해 이름 변경
typedef vector<Face> FaceGroup;

class Object {
public:
	VerticeGroup vertices;	// 정점
	NormalGroup normals;	// 법선 벡터
	TextureGroup textures;	// 텍스쳐
	FaceGroup faces;		// 면
	float color[3];			// 색상
	GLuint textureID;		// 텍스쳐
};

// 오브젝트 정보를 담는 벡터를 가독성을 위해 이름 변경
typedef vector<Object> ObjectGroup;

// 모델을 담는 클래스
class Model {
public:
	ObjectGroup objects;
	void loadModelWithObj(string filePath);
	void drawModel(GLuint *textureID, bool color, bool texture);
};