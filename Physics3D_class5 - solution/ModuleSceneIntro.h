#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);

	

public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;


	p2DynArray<Cube> BoxObject;
	p2DynArray<PhysBody3D*> PhysBody_BoxObejct;

	p2DynArray<Cube>FinalObjects;
	p2DynArray<PhysBody3D*>PhysBody_FinalObjects;
	
	p2DynArray<Cube> Obstacle;
	p2DynArray<PhysBody3D*> PhysBody_Obstacle;
	
	//Colliders to start timer and finish race
	PhysBody3D* StartCol;
	PhysBody3D* FinishCol;
	Cube startbox;
	Cube finishbox;
	
	bool started = false;

	Timer timer;
	int remainingTimer = 0;
	Timer looseTimer;


};
