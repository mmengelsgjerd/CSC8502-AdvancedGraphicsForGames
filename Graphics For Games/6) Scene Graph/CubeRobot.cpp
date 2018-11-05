#include "CubeRobot.h"

Mesh * CubeRobot::cube = NULL;

CubeRobot::CubeRobot(int i) {
	// Optional , uncomment if you want a local origin marker !
	//SetMesh(cube);
	body = new SceneNode(cube, Vector4(1, 0, 0, 1)); // Red !
	body->SetModelScale(Vector3(5, 7.5f, 2.5));
	body->SetTransform(Matrix4::Translation(Vector3((1 * i), 35, 0)));
	AddChild(body);
	
	head = new SceneNode(cube, Vector4(0, 1, 0, 1)); // Green !
	head->SetModelScale(Vector3(2.5f, 2.5f, 2.5f));
	head->SetTransform(Matrix4::Translation(Vector3(0, 15, 0)));
	body->AddChild(head);
	
	leftArm = new SceneNode(cube, Vector4(0, 0, 1, 1)); // Blue !
	leftArm->SetModelScale(Vector3(1.5f, -9, 1.5f));
	leftArm->SetTransform(Matrix4::Translation(Vector3(-6, 15, -1)));
	body->AddChild(leftArm);
	
	rightArm = new SceneNode(cube, Vector4(0, 0, 1, 1)); // Blue !
	rightArm->SetModelScale(Vector3(1.5f, -9, 1.5f));
	rightArm->SetTransform(Matrix4::Translation(Vector3(6, 15, -1)));
	body->AddChild(rightArm);
	
	leftHip = new SceneNode(cube, Vector4(0, 0, 0, 1)); // White !
	leftHip->SetModelScale(Vector3(1.5f, -4.35f, 1.5f));
	leftHip->SetTransform(Matrix4::Translation(Vector3(-4, 0, 0)));
	body->AddChild(leftHip);


	rightHip = new SceneNode(cube, Vector4(0, 0, 0, 1)); // White !
	rightHip->SetModelScale(Vector3(1.5f, -4.35f, 1.5f));
	rightHip->SetTransform(Matrix4::Translation(Vector3(4, 0, 0)));
	body->AddChild(rightHip);

	SceneNode* leftLeg = new SceneNode(cube, Vector4(0, 0, 1, 1)); // Blue !
	leftLeg->SetModelScale(Vector3(1.5f, -4.35f, 1.5f));
	leftLeg->SetTransform(Matrix4::Translation(Vector3(0, -8.7, 0)));
	leftHip->AddChild(leftLeg);
	
	SceneNode* rightLeg = new SceneNode(cube, Vector4(0, 0, 1, 1)); // Blue !
	rightLeg->SetModelScale(Vector3(1.5f, -4.35f, 1.5f));
	rightLeg->SetTransform(Matrix4::Translation(Vector3(0, -8.7, 0)));
	rightHip->AddChild(rightLeg);
	
}

void CubeRobot::Update(float msec) {
	body->SetTransform(body->GetTransform() * Matrix4::Rotation(msec / 10.0f, Vector3(0, 1, 0)));
	
	head->SetTransform(head->GetTransform() * Matrix4::Rotation(-msec / 10.0f, Vector3(0, 1, 0)));
	leftArm->SetTransform(leftArm->GetTransform() * Matrix4::Rotation(-msec / 10.0f, Vector3(1, 0, 0)));
	rightArm->SetTransform(rightArm->GetTransform() * Matrix4::Rotation(msec / 10.0f, Vector3(1, 0, 0)));
	
	if (counter < 50)
	{
		leftHip->SetTransform(leftHip->GetTransform() * Matrix4::Rotation(2.0f, Vector3(1, 0, 0)));
		rightHip->SetTransform(rightHip->GetTransform() * Matrix4::Rotation(2.0f, Vector3(-1, 0, 0)));
	}
	else
	{
		leftHip->SetTransform(leftHip->GetTransform() * Matrix4::Rotation(2.0f, Vector3(-1, 0, 0)));
		rightHip->SetTransform(rightHip->GetTransform() * Matrix4::Rotation(2.0f, Vector3(1, 0, 0)));
	}
	counter += 1;
	if (counter == 100) counter = 0;
		
	SceneNode::Update(msec);
}

