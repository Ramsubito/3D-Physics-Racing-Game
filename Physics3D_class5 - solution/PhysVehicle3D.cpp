#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Blue;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}
	//chassis
	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();
	chassis.color = Black;
	

	//upchasis
	Cube upchassis(info.upchassis_size.x, info.upchassis_size.y, info.upchassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&upchassis.transform);
	btVector3 offsetupchassis(info.upchassis_size.x, info.upchassis_size.y, info.upchassis_size.z);
	offsetupchassis = offsetupchassis.rotate(q.getAxis(), q.getAngle());
	upchassis.transform.M[12] += offsetupchassis.getX();
	upchassis.transform.M[13] += offsetupchassis.getY();
	upchassis.transform.M[14] += offsetupchassis.getZ();
	upchassis.color = Green;

	//Front Right Headlight
	Cube headlightFR(info.headlightFR_size.x, info.headlightFR_size.y, info.headlightFR_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&headlightFR.transform);
	btVector3 offsetheadlightFR(info.headlightFR_size.x, info.headlightFR_size.y, info.headlightFR_size.z);
	offsetheadlightFR = offsetheadlightFR.rotate(q.getAxis(), q.getAngle());
	headlightFR.transform.M[12] += offsetheadlightFR.getX();
	headlightFR.transform.M[13] += offsetheadlightFR.getY();
	headlightFR.transform.M[14] += offsetheadlightFR.getZ();
	headlightFR.color = Red;

	//Front Left Headlight
	Cube headlightFL(info.headlightFL_size.x, info.headlightFL_size.y, info.headlightFL_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&headlightFL.transform);
	btVector3 offsetheadlightFL(info.headlightFL_size.x, info.headlightFL_size.y, info.headlightFL_size.z);
	offsetheadlightFL = offsetheadlightFL.rotate(q.getAxis(), q.getAngle());
	headlightFL.transform.M[12] += offsetheadlightFL.getX();
	headlightFL.transform.M[13] += offsetheadlightFL.getY();
	headlightFL.transform.M[14] += offsetheadlightFL.getZ();
	headlightFL.color = Red;
	//Back Right Headlight
	Cube headlightBR(info.headlightBR_size.x, info.headlightBR_size.y, info.headlightBR_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&headlightBR.transform);
	btVector3 offsetheadlightBR(info.headlightBR_size.x, info.headlightBR_size.y, info.headlightBR_size.z);
	offsetheadlightBR = offsetheadlightBR.rotate(q.getAxis(), q.getAngle());
	headlightBR.transform.M[12] += offsetheadlightBR.getX();
	headlightBR.transform.M[13] += offsetheadlightBR.getY();
	headlightBR.transform.M[14] += offsetheadlightBR.getZ();
	headlightBR.color = Red;
	//Back Left Headlight
	Cube headlightBL(info.headlightBL_size.x, info.headlightBL_size.y, info.headlightBL_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&headlightBL.transform);
	btVector3 offsetheadlightBL(info.headlightBL_size.x, info.headlightBL_size.y, info.headlightBL_size.z);
	offsetheadlightBL = offsetheadlightBR.rotate(q.getAxis(), q.getAngle());
	headlightBL.transform.M[12] += offsetheadlightBL.getX();
	headlightBL.transform.M[13] += offsetheadlightBL.getY();
	headlightBL.transform.M[14] += offsetheadlightBL.getZ();
	headlightBL.color = Red;
	


	chassis.Render();
	upchassis.Render();
	headlightFR.Render();
	headlightFL.Render();
	headlightBR.Render();
	headlightBL.Render();

}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}
//---------------------------------------------------------------------------

