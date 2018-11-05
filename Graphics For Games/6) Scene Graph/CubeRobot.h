# pragma once
#include "SceneNode.h"
#include "../../nclgl/OBJMesh.h"

class CubeRobot : public SceneNode {
 public:
	CubeRobot(int index);
	~CubeRobot(void) {};
	virtual void Update(float msec);
	static void CreateCube() {
		OBJMesh* m = new OBJMesh();
		m->LoadOBJMesh(MESHDIR "cube.obj");
		cube = m;
	}

	static void DeleteCube() { delete cube; }
	
protected:
	static Mesh * cube;
	SceneNode* body;
	SceneNode * head;

	SceneNode* rightHip;
	SceneNode* leftHip;

	SceneNode * leftArm;
	SceneNode * rightArm;		int counter = 0;};
