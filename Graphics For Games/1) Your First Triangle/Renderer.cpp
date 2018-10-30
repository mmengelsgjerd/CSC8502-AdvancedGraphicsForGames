
#include "Renderer.h"

Renderer::Renderer(Window &parent) : OGLRenderer(parent)
{
	//triangle = Mesh::GenerateTriangle();
	house = Mesh::GenerateHouse();
	
	currentShader = new Shader(SHADERDIR"basicVertex.glsl",
							SHADERDIR"colourFragment.glsl");

	if (!currentShader->LinkProgram()) return;

	init = true;
}

Renderer::~Renderer(void)
{
	delete house;
	//delete triangle;
}

void Renderer::RenderScene()
{
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(currentShader->GetProgram());
	house->Draw();
	//triangle->Draw();
	glUseProgram(0);

	SwapBuffers();
}