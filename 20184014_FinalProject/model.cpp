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

// ���ڿ��� ��� ���͸� �������� ���� �̸� ����
typedef vector<string> Token;

// ���ڿ��� �����ڿ� ���� �и�
Token split(string str, char delim)
{
	str += delim;	// ���� ���� ���ϵ��� ������ ����

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
	cout << filePath << " ������ �ҷ��ɴϴ�\n";

	// ���� ����
	ifstream fin;
	fin.open(filePath);
	if (!fin)
	{
		cerr << "������ ã�� �� �����ϴ�\n";
		exit(1);
	}

	// ���Ͽ��� �о���µ� �ʿ��� �ӽ� ����
	int numVertex = 0;
	int numNormal = 0;
	int numTexture = 0;
	int numFaces = 0;

	string line;

	// �� �� �� ������ ����, �� ���� ����
	while(!fin.eof()){
		getline(fin, line);
		if (line.size() != 0)
		{
			if(line[0] == 'v')
			{
				if (line[1] == ' ')
					++numVertex;	// ����
				else if (line[1] == 'n')
					++numNormal;	// ����
				else if (line[1] == 't')
					++numTexture;	// �ؽ�ó
			}
			else if(line[0] == 'f')
				++numFaces;		// ��
		}
	}
	fin.clear();
	fin.seekg(ios::beg);	// rewind �� ���� ���

	cout << "���� ���� : " << numVertex << "\n";
	cout << "���� ���� : " << numNormal << "\n";
	cout << "�ؽ�ó ���� : " << numTexture << "\n";
	cout << "�� ���� : " << numFaces << "\n";

	Object obj;

	char lastCommand = ' ';

	// �� �� �� ������ ����, ���� ����, �ؽ���, �� ����
	while(!fin.eof()){
		getline(fin, line);
		if (line.size() != 0)
		{
			if(line[0] == 'v')
			{
				if (line[1] == ' ')
				{
					// �� ������Ʈ�� �Է��� ������ ��
					if (lastCommand == 'f')
					{
						objects.push_back(obj);
						obj = Object();
					}

					// ���� �и��Ͽ� ���� ��ǥ�� ���� ��: v 1 1 1
					Token token = split(line.substr(3, line.size()-3), ' ');
					Point3f p = { stof(token[0]), stof(token[1]), stof(token[2]) };
					obj.vertices.push_back(p);

					lastCommand = 'v';
				}
				else if (line[1] == 'n')
				{
					// ���� �и��Ͽ� ���� ���� ��ǥ�� ���� ��: vn 1 1 1
					Token token = split(line.substr(3, line.size()-2), ' ');
					Point3f p = { stof(token[0]), stof(token[1]), stof(token[2]) };
					obj.normals.push_back(p);					
				}
				else if (line[1] == 't')
				{
					// ���� �и��Ͽ� �ؽ��� ��ǥ�� ���� ��: vt 1 1 1
					Token token = split(line.substr(3, line.size()-2), ' ');
					Point3f p = { stof(token[0]), stof(token[1]), stof(token[2]) };
					obj.textures.push_back(p);
				}
			}
			else if(line[0] == 'f')
			{
				// ����/�ؽ���/�������� ������ ���� �и��Ͽ� ���� ��: f 1/2/3 1/2/3 1/2/3
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
		v, vn, vt, o, f ������ �ۼ��Ǿ� �־� f ������ v�� �� ������
		���ο� ������Ʈ�� �����ϸ� �ȴ�.
		������ ������Ʈ�� �а� ���� v�� ������ �����Ƿ�
		�ݺ����� ������ ��ݱ��� �а� �ִ� ������Ʈ�� ����Ʈ�� �־��� ��
	*/
	objects.push_back(obj);


	cout << "������Ʈ ���� : " << objects.size() << "\n";
	cout << "������ �ҷ��Խ��ϴ�\n";
	fin.close();

	cout << "color.txt ������ �ҷ��ɴϴ�\n";

	// ���� ����
	fin.open("color.txt");
	if (!fin)
	{
		cerr << "������ ã�� �� �����ϴ�\n";
		exit(1);
	}

	int o = 0;

	while(!fin.eof()){
		fin >> objects[o].color[0] >> objects[o].color[1] >> objects[o].color[2];
		++o;
	}
	cout << "������Ʈ ������ �ҷ��Խ��ϴ�\n";
	fin.close();

	cout << "texture.txt ������ �ҷ��ɴϴ�\n";

	// ���� ����
	fin.open("texture.txt");
	if (!fin)
	{
		cerr << "������ ã�� �� �����ϴ�\n";
		exit(1);
	}

	o = 0;

	while(!fin.eof()){
		fin >> objects[o].textureID;
		++o;
	}
	cout << "������Ʈ �ؽ��ĸ� �ҷ��Խ��ϴ�\n";
	fin.close();
}

void Model::drawModel(GLuint *textureID, bool color, bool texture)
{
	int object_amount = objects.size();
	
	int last_vertice_amount = 0;

	// �ؽ��� ��� ���� Ȯ��
	if (!texture) glDisable(GL_TEXTURE_2D);

	// ��� ������Ʈ�� �׷���
	for (int o=0; o<object_amount; ++o)
	{
		int face_amount = objects[o].faces.size();
		
		glPushMatrix();

		// ���� ��� ���� Ȯ��
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

		// ��� ���� ���� ����, �ؽ���, ���� ��ǥ�� ��������
		// ������ �ٸ��� �ȵ�
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
			ù��° ������Ʈ�� ������ 10�����ٸ�
			�ι�° ������Ʈ�� ���� �׸� �� ���� ��ȣ�� 11���� ����.
			������ �̰��� ��ü������ ���� �� 11���� ���̰�
			�ι�° ������Ʈ�� ���ؿ��� 1�� �����̹Ƿ�
			�ٷ� �� ������Ʈ������ ���� ������ �����صξ��ٰ�
			�ش� ���� ���� ��ȣ���� ���־�� �߸��� ������ ���� �ʰ� �ȴ�.
		*/
		last_vertice_amount += objects[o].vertices.size();
	}
}