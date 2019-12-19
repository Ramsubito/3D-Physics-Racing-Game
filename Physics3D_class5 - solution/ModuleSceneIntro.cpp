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
	//make Ramps->Add angle

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
	//First straight--------------------------------------
	Cube Box2;
	PhysBody3D*BodyObject2;
	Box2.size.x = 16;
	Box2.size.z = 150;
	BoxObject.PushBack(Box2);
	BodyObject2 = App->physics->AddBody(Box2, 0);
	BodyObject2->SetPos(0, 0,80);
	PhysBody_BoxObejct.PushBack(BodyObject2);
	//Box2.color = Blue;
	//Delimitations

	
	
	//-------------------------------------------------------------------------
	//First curve left
	Cube Box3;
	PhysBody3D*BodyObject3;
	Box3.size.x = 50;
	Box3.size.z = 14;
	BoxObject.PushBack(Box3);
	BodyObject3 = App->physics->AddBody(Box3, 0);
	BodyObject3->SetPos(32, 0, 150);
	PhysBody_BoxObejct.PushBack(BodyObject3);
	//-------------------------------------------------------------------------
	
	//Wider spot third part
	Cube Box4;
	PhysBody3D*BodyObject4;
	Box4.size.x = 160;
	Box4.size.z = 90;
	BoxObject.PushBack(Box4);
	BodyObject4 = App->physics->AddBody(Box4, 0);
	BodyObject4->SetPos(130, 0, 155);
	PhysBody_BoxObejct.PushBack(BodyObject4);
	//-------------------------------------------------------------------------

	//Obstacles wider spot Appear randomly inside the box created
for (int i = 0; i <= 35; i++) {
	/*for (int x = 110; x <= 205; x += rand()%15+15) {
		for (int z = 130; z <= 180; z += rand()%15 + 15) {*/
	Cube Obstacle1;
	PhysBody3D* BodyObstacle1;
	Obstacle1.size.x = 1.5;
	Obstacle1.size.z = 1.5;
	Obstacle1.size.y = 15;
	Obstacle.PushBack(Obstacle1);
	BodyObstacle1 = App->physics->AddBody(Obstacle1, 0);
	BodyObstacle1->SetPos(rand() % 120 + 70, 0, rand() % 100 + 110);
	PhysBody_Obstacle.PushBack(BodyObstacle1);
	//Obstacle.color = Green;
	//-------------------------------------------------------------------------

}
/*}
}*/
//Ramp1
Cube Box5;
PhysBody3D*BodyObject5;
Box5.size.x = 60;
Box5.size.z = 20;
Box5.SetRotation(1.1, vec3(1, 0, 0));
Box5.SetRotation(15, vec3(0, 0, 1));
BoxObject.PushBack(Box5);
BodyObject5 = App->physics->AddBody(Box5, 0);
BodyObject5->SetPos(210, 6, 150);
PhysBody_BoxObejct.PushBack(BodyObject5);
//-------------------------------------------------------------------------

//Continuation ramp plane
Cube Box6;
PhysBody3D*BodyObject6;
Box6.size.x = 60;
Box6.size.z = 30;
Box6.size.y = 5;
BoxObject.PushBack(Box6);
BodyObject6 = App->physics->AddBody(Box6, 0);
BodyObject6->SetPos(315, 12, 155);
PhysBody_BoxObejct.PushBack(BodyObject6);

//-------------------------------------------------------------------------
//go left from platform
Cube Box7;
PhysBody3D*BodyObject7;
Box7.size.x = 15;
Box7.size.z = 90;
Box7.size.y = 5;
BoxObject.PushBack(Box7);
BodyObject7 = App->physics->AddBody(Box7, 0);
BodyObject7->SetPos(315, 12, 95);
PhysBody_BoxObejct.PushBack(BodyObject7);

//-------------------------------------------------------------------------
//Go down
Cube Box8;
PhysBody3D*BodyObject8;
Box8.size.x = 15;
Box8.size.z = 50;
BoxObject.PushBack(Box8);
Box8.SetRotation(-10, vec3(1, 0, 0));
BodyObject8 = App->physics->AddBody(Box8, 0);
BodyObject8->SetPos(315, 10, 30);
PhysBody_BoxObejct.PushBack(BodyObject8);

//Down Platform square
Cube Box9;
PhysBody3D*BodyObject9;
Box9.size.x = 20;
Box9.size.z = 20;
Box9.size.y = 12;
BoxObject.PushBack(Box9);
BodyObject9 = App->physics->AddBody(Box9, 0);
BodyObject9->SetPos(315, -1.5, -5);
PhysBody_BoxObejct.PushBack(BodyObject9);
//go left/down center
Cube Box10;
PhysBody3D*BodyObject10;
Box10.size.x = 50;
Box10.size.z = 20;
Box10.SetRotation(5, vec3(0, 0, 1));
BoxObject.PushBack(Box10);
BodyObject10 = App->physics->AddBody(Box10, 0);
BodyObject10->SetPos(280, 1, -5);
PhysBody_BoxObejct.PushBack(BodyObject10);

//final obstacle path


Cube Final1;
PhysBody3D*BodyFinal1;
Final1.size.x = 100;
Final1.size.z = 100;
FinalObjects.PushBack(Final1);
BodyFinal1 = App->physics->AddBody(Final1, 0);
BodyFinal1->SetPos(220, 0, -5);
PhysBody_FinalObjects.PushBack(BodyFinal1);

//final Obstacles

//Final line
Cube Final2;
PhysBody3D*BodyFinal2;
Final2.size.x = 200;
Final2.size.z = 15;
FinalObjects.PushBack(Final2);
BodyFinal2 = App->physics->AddBody(Final2, 0);
BodyFinal2->SetPos(75, 0, -5);
PhysBody_FinalObjects.PushBack(BodyFinal2);

//victory sign End
Cube Final3;
PhysBody3D*BodyFinal3;
Final3.size.x = 0.5;
Final3.size.z = 0.5;
Final3.size.y = 12;
FinalObjects.PushBack(Final3);
BodyFinal3 = App->physics->AddBody(Final3, 0);
BodyFinal3->SetPos(-6, 5, 1);
PhysBody_FinalObjects.PushBack(BodyFinal3);


Cube Final4;
PhysBody3D*BodyFinal4;
Final4.size.x = 0.5;
Final4.size.z = 0.5;
Final4.size.y = 12;
FinalObjects.PushBack(Final4);
BodyFinal4 = App->physics->AddBody(Final4, 0);
BodyFinal4->SetPos(-6, 5, -10);
PhysBody_FinalObjects.PushBack(BodyFinal4);

Cube Final5;
PhysBody3D*BodyFinal5;
Final5.size.x = 0.1;
Final5.size.z = 11;
Final5.size.y = 2;
FinalObjects.PushBack(Final5);
BodyFinal5 = App->physics->AddBody(Final5, 0);
BodyFinal5->SetPos(-6, 11, -4.5);
PhysBody_FinalObjects.PushBack(BodyFinal5); 



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
	for (int i = 0; i < Obstacle.Count(); i++) {
		Obstacle[i].Render();
		PhysBody_Obstacle[i]->GetTransform(&Obstacle[i].transform);


	}
	for (int i = 0; i < FinalObjects.Count(); i++) {
		FinalObjects[i].Render();
		PhysBody_FinalObjects[i]->GetTransform(&FinalObjects[i].transform);


	}
	



		return UPDATE_CONTINUE;
	
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
	
}

