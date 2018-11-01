
#include "Mesh.h"

Mesh::Mesh(void) {
	for (int i = 0; i < MAX_BUFFER; ++i)
	{
		bufferObject[i] = 0;
	}
	glGenVertexArrays(1, &arrayObject);

	numVertices = 0;
	vertices = NULL;
	colours = NULL;
	type = GL_TRIANGLES;

	//Tutorial 3
	texture = 0;
	textureCoords = NULL;
}

Mesh::~Mesh(void)
{
	glDeleteVertexArrays(1, &arrayObject);
	glDeleteBuffers(MAX_BUFFER, bufferObject);
	delete[] vertices;
	delete[] colours;

	//Tutorial 3
	glDeleteTextures(1, &texture);
	delete[]textureCoords;
}

Mesh* Mesh::GenerateTriangle()
{
	Mesh* m = new Mesh();
	m->numVertices = 3;

	m->vertices = new Vector3[m->numVertices];

	m->vertices[0] = Vector3(0.0f, 0.5f, 0.0f);
	m->vertices[1] = Vector3(0.5f, -0.5f, 0.0f);
	m->vertices[2] = Vector3(-0.5f, -0.5f, 0.0f);

	//Tutorial 3
	m->textureCoords = new Vector2[m->numVertices];
	m->textureCoords[0] = Vector2(0.5f, 0.0f);
	m->textureCoords[1] = Vector2(1.0f, 1.0f);
	m->textureCoords[2] = Vector2(0.0f, 1.0f);

	m->colours = new Vector4[m->numVertices];
	m->colours[0] = Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	m->colours[1] = Vector4(0.0f, 1.0f, 0.0f, 1.0f);
	m->colours[2] = Vector4(0.0f, 0.0f, 1.0f, 1.0f);

	m->BufferData();
	return m;
 }

Mesh* Mesh::GenerateHouse()
{
	Mesh* m = new Mesh();
	m->numVertices = 33;

	m->vertices = new Vector3[m->numVertices];
	//x, y, z
	m->vertices[0] = Vector3(-0.5f, 0.5f, 0.0f);
	m->vertices[1] = Vector3(-0.5f, -0.5f, 0.0f);
	m->vertices[2] = Vector3(0.5f, -0.5f, 0.0f);
	
	m->vertices[3] = Vector3(0.5f, -0.5f, 0.0f);
	m->vertices[4] = Vector3(0.5f, 0.5f, 0.0f);
	m->vertices[5] = Vector3(-0.5f, 0.5f, 0.0f);
	
	m->vertices[6] = Vector3(-0.5f, 0.5f, 0.0f);
	m->vertices[7] = Vector3(0.0f, 1.0f, 0.0f);
	m->vertices[8] = Vector3(0.5f, 0.5f, 0.0f);
	
	m->vertices[9] = Vector3(0.3f, 0.50f, 0.0f);
	m->vertices[10] = Vector3(0.3f, 0.9f, 0.0f);
	m->vertices[11] = Vector3(0.35f, 0.9f, 0.0f);
	
	m->vertices[12] = Vector3(0.35f, 0.9f, 0.0f);
	m->vertices[13] = Vector3(0.35f, 0.50f, 0.0f);
	m->vertices[14] = Vector3(0.3f, 0.5f, 0.0f);

	m->vertices[15] = Vector3(-0.3f, 0.0f, 0.0f);
	m->vertices[16] = Vector3(-0.1f, 0.0f, 0.0f);
	m->vertices[17] = Vector3(-0.3f, -0.5f, 0.0f);

	m->vertices[18] = Vector3(-0.1f, 0.0f, 0.0f);
	m->vertices[19] = Vector3(-0.1f, -0.5f, 0.0f);
	m->vertices[20] = Vector3(-0.3f, -0.5f, 0.0f);

	m->vertices[21] = Vector3(0.1f, -0.25f, 0.0f);
	m->vertices[22] = Vector3(0.2f, -0.25f, 0.0f);
	m->vertices[23] = Vector3(0.1f, 0.0f, 0.0f);
	
	m->vertices[24] = Vector3(0.2f, -0.25f, 0.0f);
	m->vertices[25] = Vector3(0.2f, 0.0f, 0.0f);
	m->vertices[26] = Vector3(0.1f, 0.0f, 0.0f);

	m->vertices[27] = Vector3(0.25f, -0.25f, 0.0f);
	m->vertices[28] = Vector3(0.35f, -0.25f, 0.0f);
	m->vertices[29] = Vector3(0.25f, 0.0f, 0.0f);

	m->vertices[30] = Vector3(0.35f, -0.25f, 0.0f);
	m->vertices[31] = Vector3(0.35f, 0.0f, 0.0f);
	m->vertices[32] = Vector3(0.25f, 0.0f, 0.0f);
	
	
	m->colours = new Vector4[m->numVertices];
	for (int i = 0; i < m->numVertices-18; i++)
	{
		m->colours[i] = Vector4(1.0f, 0.50f, 0.0f, 1.0f);
	}


	m->BufferData();
	return m;
}

void Mesh::BufferData()
{
	glBindVertexArray(arrayObject);
	glGenBuffers(1, &bufferObject[VERTEX_BUFFER]);
	glBindBuffer(GL_ARRAY_BUFFER, bufferObject[VERTEX_BUFFER]);
	glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vector3), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(VERTEX_BUFFER, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(VERTEX_BUFFER);

	//Tutorial 3
	if (textureCoords)
	{
		glGenBuffers(1, &bufferObject[TEXTURE_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, bufferObject[TEXTURE_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vector2), textureCoords, GL_STATIC_DRAW);
		glVertexAttribPointer(TEXTURE_BUFFER, 2, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(TEXTURE_BUFFER);
	}


	if (colours) { // Just in case the data has no colour attribute ...
		glGenBuffers(1, &bufferObject[COLOUR_BUFFER]);
		glBindBuffer(GL_ARRAY_BUFFER, bufferObject[COLOUR_BUFFER]);
		glBufferData(GL_ARRAY_BUFFER, numVertices * sizeof(Vector4), colours, GL_STATIC_DRAW);
		glVertexAttribPointer(COLOUR_BUFFER, 4, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray(COLOUR_BUFFER);
		
	}
	glBindVertexArray(0);

}

void Mesh::Draw()
{
	//Tutorial 3
	glBindTexture(GL_TEXTURE_2D, texture);

	glBindVertexArray(arrayObject);
	glDrawArrays(type, 0, numVertices);
	glBindVertexArray(0);

	//Tutorial 3
	glBindTexture(GL_TEXTURE_2D, 0);
}

//Tutorial 4
Mesh* Mesh::GenerateQuad()
{
	Mesh* m = new Mesh();
	m->numVertices = 4;
	m->type = GL_TRIANGLE_STRIP;

	m->vertices = new Vector3[m->numVertices];
	m->textureCoords = new Vector2[m->numVertices];
	m->colours = new Vector4[m->numVertices];

	m->vertices[0] = Vector3(-1.0f, -1.0f, 0.0f);
	m->vertices[1] = Vector3(-1.0f, 1.0f, 0.0f);
	m->vertices[2] = Vector3(1.0f, -1.0f, 0.0f);
	m->vertices[3] = Vector3(1.0f, 1.0f, 0.0f);

	m->textureCoords[0] = Vector2(0.0f, 1.0f);
	m->textureCoords[1] = Vector2(0.0f, 0.0f);
	m->textureCoords[2] = Vector2(1.0f, 1.0f);
	m->textureCoords[3] = Vector2(1.0f, 0.0f);

	for (int i = 0; i < 4; ++i)
	{
		m->colours[i] = Vector4(1.0f, 1.0f, 1.0f, 1.0f);
	}

	m->BufferData();
	return m;

}