#pragma once


#include "../../nclgl/OGLRenderer.h"

class Renderer2 : public OGLRenderer
{
public:
	Renderer2(Window &parent);
	virtual ~Renderer2(void);

	virtual void RenderScene();

	void ToggleScissor();
	void ToggleStencil();

protected:
	Mesh* triangle;
	Mesh* quad;

	bool usingScissor;
	bool usingStencil;
};
