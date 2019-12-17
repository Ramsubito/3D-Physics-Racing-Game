#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

struct PhysVehicle3D;

#define MAX_ACCELERATION 1000.0f
#define TURN_DEGREES 15.0f * DEGTORAD
#define BRAKE_POWER 1000.0f

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();
	void reset_playe();
	//player position in world from a vector given
	vec3 World_to_Player(vec3, bool translate = true); 
	vec3 Player_to_World(vec3, bool translate = true);

public:

	PhysVehicle3D* vehicle;
	float turn;
	float acceleration;
	float brake;
	bool win = false;
	bool lose = false;
	float z = 0;
	float speed = 0;
};