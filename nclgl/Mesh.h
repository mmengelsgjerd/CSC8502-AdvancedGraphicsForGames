#pragma once
#include "OGLRenderer.h"

enum MeshBuffer {
	VERTEX_BUFFER, COLOUR_BUFFER, TEXTURE_BUFFER,
	NORMAL_BUFFER, INDEX_BUFFER, MAX_BUFFER
};

class Mesh {
public:
	Mesh(void);
	~Mesh(void);

	virtual void Draw();
	static Mesh* GenerateTriangle();
	static Mesh* GenerateHouse();

	//Tutorial 3
	void SetTexture(GLuint tex) { texture = tex; }
	GLuint GetTexture() { return texture; }

	//Tutorial 4
	static Mesh* GenerateQuad();

protected:
	void BufferData();

	GLuint arrayObject;
	GLuint bufferObject[MAX_BUFFER];
	GLuint numVertices;
	GLuint type;

	Vector3* vertices;
	Vector4* colours;

	//Tutorial 3
	GLuint texture;
	Vector2* textureCoords;

	//Tutorial 8
	GLuint numIndices;
	unsigned int* indices;

	//Tutorial 11
	void GenerateNormals();
	Vector3* normals;
};
