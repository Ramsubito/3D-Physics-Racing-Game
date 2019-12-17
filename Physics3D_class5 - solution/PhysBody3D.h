#ifndef __PhysBody3D_H__
#define __PhysBody3D_H__

#include "p2List.h"
#include "glmath.h"

class btRigidBody;
class Module;

// =================================================
struct PhysBody3D
{
	friend class ModulePhysics3D;
public:
	PhysBody3D(btRigidBody* body, vec3 size1);
	~PhysBody3D();

	void Push(float x, float y, float z);
	void GetTransform(float* matrix) const;
	vec3 GetPosition();
	mat3x3 GetRotation();
	
	void SetTransform(const float* matrix) const;
	void SetRotation(mat3x3);
	void SetTransform(const float* matrix) const;
	void SetPos(float x, float y, float z);
	void SetAsSensor(bool sensorcheck);
	bool SensorCheck() const;
	
	vec3 size;

private:
	btRigidBody* body = nullptr;
	bool sensorcheck = false;

public:
	p2List<Module*> collision_listeners;
};

#endif // __PhysBody3D_H__