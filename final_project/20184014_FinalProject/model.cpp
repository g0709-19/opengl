#include "model.h"
#include <iostream>
#include <fstream>
#include <string>

#include <GL/glut.h>

float* Point3f::toArray()
{
	float arr[] = { x, y, z };
	return arr;
}

// 문자열을 담는 벡터를 가독성을 위해 이름 변경
typedef vector<string> Token;

// 문자열을 구분자에 맞춰 분리
Token split(string str, char delim)
{
	str += delim;	// 개수 세기 편하도록 구분자 삽입

	Token token;
	int start = 0;
	for (int i=0, size=str.size(); i<size; ++i)
	{
		if (str[i] == delim)
		{
			token.push_back(str.substr(start, i-start));
			start = i+1;
		}
	}
	return token;
}

void Model::loadModelWithObj(string filePath)
{
	cout << filePath << " 파일을 불러옵니다\n";

	// 파일 열기
	ifstream fin;
	fin.open(filePath);
	if (!fin)
	{
		cerr << "파일을 찾을 수 없습니다\n";
		exit(1);
	}

	// 파일에서 읽어오는데 필요한 임시 변수
	int numVertex = 0;
	int numNormal = 0;
	int numTexture = 0;
	int numFaces = 0;

	string line;

	// 한 줄 씩 읽으며 정점, 면 개수 측정
	while(!fin.eof()){
		getline(fin, line);
		if (line.size() != 0)
		{
			if(line[0] == 'v')
			{
				if (line[1] == ' ')
					++numVertex;	// 정점
				else if (line[1] == 'n')
					++numNormal;	// 법선
				else if (line[1] == 't')
					++numTexture;	// 텍스처
			}
			else if(line[0] == 'f')
				++numFaces;		// 면
		}
	}
	fin.clear();
	fin.seekg(ios::beg);	// rewind 와 같은 기능

	cout << "정점 개수 : " << numVertex << "\n";
	cout << "법선 개수 : " << numNormal << "\n";
	cout << "텍스처 개수 : " << numTexture << "\n";
	cout << "면 개수 : " << numFaces << "\n";

	Object obj;

	char lastCommand = ' ';

	// 한 줄 씩 읽으며 정점, 법선 벡터, 텍스쳐, 면 저장
	while(!fin.eof()){
		getline(fin, line);
		if (line.size() != 0)
		{
			if(line[0] == 'v')
			{
				if (line[1] == ' ')
				{
					// 한 오브젝트의 입력이 끝났을 때
					if (lastCommand == 'f')
					{
						objects.push_back(obj);
						obj = Object();
					}

					// 숫자 분리하여 정점 좌표로 삽입 예: v 1 1 1
					Token token = split(line.substr(3, line.size()-3), ' ');
					Point3f p = { stof(token[0]), stof(token[1]), stof(token[2]) };
					obj.vertices.push_back(p);

					lastCommand = 'v';
				}
				else if (line[1] == 'n')
				{
					// 숫자 분리하여 법선 벡터 좌표로 삽입 예: vn 1 1 1
					Token token = split(line.substr(3, line.size()-2), ' ');
					Point3f p = { stof(token[0]), stof(token[1]), stof(token[2]) };
					obj.normals.push_back(p);					
				}
				else if (line[1] == 't')
				{
					// 숫자 분리하여 텍스쳐 좌표로 삽입 예: vt 1 1 1
					Token token = split(line.substr(3, line.size()-2), ' ');
					Point3f p = { stof(token[0]), stof(token[1]), stof(token[2]) };
					obj.textures.push_back(p);
				}
			}
			else if(line[0] == 'f')
			{
				// 정점/텍스쳐/법선벡터 순으로 숫자 분리하여 삽입 예: f 1/2/3 1/2/3 1/2/3
				Token token = split(line.substr(2, line.size()-3), ' ');
				Token token1 = split(token[0], '/');
				Point3i p1 = { stoi(token1[0]), stoi(token1[1]), stoi(token1[2]) };
				Token token2 = split(token[1], '/');
				Point3i p2 = { stoi(token2[0]), stoi(token2[1]), stoi(token2[2]) };
				Token token3 = split(token[2], '/');
				Point3i p3 = { stoi(token3[0]), stoi(token3[1]), stoi(token3[2]) };
				Face f = { p1, p2, p3 };
				obj.faces.push_back(f);

				lastCommand = 'f';				
			}
		}
	}
	/*
		v, vn, vt, o, f 순으로 작성되어 있어 f 다음에 v가 올 때마다
		새로운 오브젝트를 생성하면 된다.
		마지막 오브젝트를 읽고 나면 v가 나오지 않으므로
		반복문이 끝나고 방금까지 읽고 있던 오브젝트를 리스트에 넣어준 것
	*/
	objects.push_back(obj);


	cout << "오브젝트 개수 : " << objects.size() << "\n";
	cout << "파일을 불러왔습니다\n";
	fin.close();

	cout << "color.txt 파일을 불러옵니다\n";

	// 파일 열기
	fin.open("color.txt");
	if (!fin)
	{
		cerr << "파일을 찾을 수 없습니다\n";
		exit(1);
	}

	int o = 0;

	while(!fin.eof()){
		fin >> objects[o].color[0] >> objects[o].color[1] >> objects[o].color[2];
		++o;
	}
	cout << "오브젝트 색상을 불러왔습니다\n";
	fin.close();

	cout << "texture.txt 파일을 불러옵니다\n";

	// 파일 열기
	fin.open("texture.txt");
	if (!fin)
	{
		cerr << "파일을 찾을 수 없습니다\n";
		exit(1);
	}

	o = 0;

	while(!fin.eof()){
		fin >> objects[o].textureID;
		++o;
	}
	cout << "오브젝트 텍스쳐를 불러왔습니다\n";
	fin.close();
}

void Model::drawModel(GLuint *textureID, bool color, bool texture)
{
	int object_amount = objects.size();
	
	int last_vertice_amount = 0;

	// 텍스쳐 모드 여부 확인
	if (!texture) glDisable(GL_TEXTURE_2D);

	// 모든 오브젝트를 그려줌
	for (int o=0; o<object_amount; ++o)
	{
		int face_amount = objects[o].faces.size();
		
		glPushMatrix();

		// 색상 모드 여부 확인
		if (color)
		{
			glColor3fv(objects[o].color);
			GLfloat mat_ambient[] = { objects[o].color[0], objects[o].color[1], objects[o].color[2] };
			GLfloat mat_diffuse[] = { objects[o].color[0], objects[o].color[1], objects[o].color[2] };
			GLfloat mat_specular[] = { 0.1, 0.1, 0.1 };
			GLfloat mat_shininess[] = { 100.0 };
			glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
			glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
			glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
			glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
		}

		glBindTexture(GL_TEXTURE_2D, textureID[objects[o].textureID]);

		// 모든 면의 법선 벡터, 텍스쳐, 정점 좌표를 지정해줌
		// 순서가 다르면 안됨
		glBegin(GL_TRIANGLES);
		for (int f=0; f<face_amount; ++f)
		{
			glNormal3fv(objects[o].normals[objects[o].faces[f].p1.v3-last_vertice_amount-1].toArray());
			glTexCoord3fv(objects[o].textures[objects[o].faces[f].p1.v2-last_vertice_amount-1].toArray());
			glVertex3fv(objects[o].vertices[objects[o].faces[f].p1.v1-last_vertice_amount-1].toArray());

			glNormal3fv(objects[o].normals[objects[o].faces[f].p2.v3-last_vertice_amount-1].toArray());
			glTexCoord3fv(objects[o].textures[objects[o].faces[f].p2.v2-last_vertice_amount-1].toArray());
			glVertex3fv(objects[o].vertices[objects[o].faces[f].p2.v1-last_vertice_amount-1].toArray());

			glNormal3fv(objects[o].normals[objects[o].faces[f].p3.v3-last_vertice_amount-1].toArray());
			glTexCoord3fv(objects[o].textures[objects[o].faces[f].p3.v2-last_vertice_amount-1].toArray());
			glVertex3fv(objects[o].vertices[objects[o].faces[f].p3.v1-last_vertice_amount-1].toArray());
		}
		glEnd();

		glPopMatrix();

		/*
			첫번째 오브젝트의 정점이 10개였다면
			두번째 오브젝트의 면을 그릴 때 정점 번호를 11부터 센다.
			하지만 이것은 전체적으로 봤을 때 11번인 것이고
			두번째 오브젝트의 기준에서 1번 정점이므로
			바로 전 오브젝트까지의 정점 개수를 저장해두었다가
			해당 면의 정점 번호에서 빼주어야 잘못된 참조를 하지 않게 된다.
		*/
		last_vertice_amount += objects[o].vertices.size();
	}
}