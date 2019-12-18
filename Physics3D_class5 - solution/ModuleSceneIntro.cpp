#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	//Create Map


	//RAMP
	//make Ramps->Add angle(10)moreless
	/*Cube Box1;
	PhysBody3D* BodyObject1;
	Box1.size.x = 10;
	Box1.size.z = 10;
	
	Box1.SetRotation(80, vec3(1, 0, 0));
	
	BoxObject.PushBack(Box1);
	BodyObject1 = App->physics->AddBody(Box1, 0);
	BodyObject1->SetPos(0.5, 8.5, 53);
	PhysBody_BoxObejct.PushBack(BodyObject1);
	Box1.color = Blue;*/

	//ASFALT
	
	Cube Box2;
	PhysBody3D*BodyObject2;
	Box2.size.x = 16;
	Box2.size.z = 200;
	BoxObject.PushBack(Box2);
	BodyObject2 = App->physics->AddBody(Box2, 0);
	BodyObject2->SetPos(0, 0, 2);
	PhysBody_BoxObejct.PushBack(BodyObject2);
	Box2.color = Blue;
	/*
	Cube Box3;
	PhysBody3D*BodyObject3;
	Box3.size.x = 16;
	Box3.size.z = 8;
	BoxObject.PushBack(Box3);
	BodyObject3 = App->physics->AddBody(Box3, 0);
	BodyObject3->SetPos(51.5, 0, 105.5);
	PhysBody_BoxObejct.PushBack(BodyObject3);
	Box3.color = Blue; */
	/*
	Cube Box4;
	PhysBody3D*BodyObject4;
	Box4.size.x = 16;
	Box4.size.z = 8;
	BoxObject.PushBack(Box4);
	BodyObject4 = App->physics->AddBody(Box4, 0);
	BodyObject4->SetPos(51.5, 0, 113.5);
	PhysBody_BoxObejct.PushBack(BodyObject4);
	Box4.color = Blue; */
	/*
	Cube Box5;
	PhysBody3D*BodyObject5;
	Box5.size.x = 16;
	Box5.size.z = 200;
	BoxObject.PushBack(Box5);
	BodyObject5 = App->physics->AddBody(Box5, 0);
	BodyObject5->SetPos(94.5, 0, 2);
	PhysBody_BoxObejct.PushBack(BodyObject5);
	Box5.color = Blue; */
	/*
	Cube Box6;
	PhysBody3D*BodyObject6;
	Box6.size.x = 16;
	Box6.size.z = 200;
	BoxObject.PushBack(Box6);
	BodyObject6 = App->physics->AddBody(Box6, 0);
	BodyObject6->SetPos(102.5, 0, 2);
	PhysBody_BoxObejct.PushBack(BodyObject6);
	Box6.color = Blue; */
	/*
	Cube Box7;
	PhysBody3D*BodyObject7;
	Box7.size.x = 16;
	Box7.size.z = 8;
	BoxObject.PushBack(Box7);
	BodyObject7 = App->physics->AddBody(Box7, 0);
	BodyObject7->SetPos(51.5, 0, -102);
	PhysBody_BoxObejct.PushBack(BodyObject7);
	Box7.color = Blue; */
	/*
	Cube Box8;
	PhysBody3D*BodyObject8;
	Box8.size.x = 16;
	Box8.size.z = 8;
	BoxObject.PushBack(Box8);
	BodyObject8 = App->physics->AddBody(Box8, 0);
	BodyObject8->SetPos(51.5, 0, -110);
	PhysBody_BoxObejct.PushBack(BodyObject8);
	Box8.color = Blue; */

	

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	for (int i = 0; i < BoxObject.Count(); i++) {
		BoxObject[i].Render();
		PhysBody_BoxObejct[i]->GetTransform(&BoxObject[i].transform);
		
	}

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

