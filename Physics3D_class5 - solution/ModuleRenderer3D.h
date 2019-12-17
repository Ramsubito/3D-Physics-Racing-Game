#pragma once
#include "Module.h"
#include "Globals.h"
#include "glmath.h"
#include "Light.h"

#define MAX_LIGHTS 8
#define GRAVITY btVector(0.0f, -10.0f , 0.0f)

class DebugDraw;
struct PhysBody3D;
struct PhysVehicle3D;
struct VehicleInfo;


class ModuleRenderer3D : public Module
{
public:
	ModuleRenderer3D(Application* app, bool start_enabled = true);
	~ModuleRenderer3D();
	
	bool Init();
	update_status PreUpdate(float dt);
	update_status Update(float dt);
	update_status PostUpdate(float dt);
	bool CleanUp();

	//create scene
	PhysBody3D* CreateBody(const Sphere& sphere, float mass = 1.0f);
	PhysBody3D* CreateBody(const Cube& cube, float mass = 1.0f, bool is_sensor = false);
	PhysBody3D* CreateBody(const Cylinder& cylinder, float mass = 1.0f);
	PhysVehicle3D* CreateVehicle(const VehicleInfo& info);
	btHingeConstraint* Add_Hinge_Constraint(btRigidBody& rbA, btRigidBody& rbB, const btVector3& pivotInA, const btVector3& pivotInB, btVector3& axisInA, btVector3& axisInB, bool disablecollision);
	btPoint2PointConstraint* Add_P2P_Constraint(btRigidBody& rbA, btRigidBody& rbB, const btVector3& pivotInA, const btVector3& pivotInB, bool disablecollision);
	void AddConstraintP2P(PhysBody3D& bodyA, PhysBody3D& bodyB, const vec3& anchorA, const vec3& anchorB);
	void AddConstraintHinge(PhysBody3D& bodyA, PhysBody3D& bodyB, const vec3& anchorA, const vec3& anchorB, const vec3& axisS, const vec3& axisB, bool disable_collision = false);
	

	void OnResize(int width, int height);

public:

	Light lights[MAX_LIGHTS];
	SDL_GLContext context;
	mat3x3 NormalMatrix;
	mat4x4 ModelMatrix, ViewMatrix, ProjectionMatrix;

private:
	bool debug;

	btDefaultCollisionConfiguration*	Collision_config;
	btCollisionDispatcher*				Dispatcher;
	btBroadphaseInterface*				Broad_ihase_interface;
	btSequentialImpulseConstraintSolver* Constraint_solver;
	btDiscreteDynamicsWorld*			World;
	btDefaultVehicleRaycaster*			Vehicle_raycaster;
	DebugDrawer*						Debug_draw;

	p2List<btCollisionShape*> shape;
	p2List<PhysBody3D*> bodies;
	p2List<btDefaultMotionState*> motion;
	p2List<btTypedConstraint*> constraint;
	p2List<PhysVehicle3D*> vehicle;
	p2DynArray<Sphere> CanonBallsSpheres;
	p2DynArray<PhysBody3D*> CanonBallsBody;

};

class DebugDraw : public btIDebugDraw
{
public:
	DebugDraw() : line(0, 0, 0)
	{}
	void drawLine(const btVector3& from, const btVector3& to, const btVector3& color);
	void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color);
	void reportErrorWarning(const char* warningString);
	void draw3dText(const btVector3& location, const char* textString);
	void setDebugMode(int debugMode);
	int	 getDebugMode() const;

	DebugDrawModes mode;
	Line line;
	Primitive point;


};