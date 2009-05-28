/*
 *	server/zone/objects/SceneObject.h generated by engine3 IDL compiler 0.55
 */

#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedObject.h"

class SceneObject : public ManagedObject {
public:
	void info(const String& message, bool forcedLog = false);

	void error(const String& message);

protected:
	SceneObject(DummyConstructorParameter* param);

	virtual ~SceneObject();

	friend class SceneObjectHelper;
};

class SceneObjectImplementation;

class SceneObjectAdapter : public ManagedObjectAdapter {
public:
	SceneObjectAdapter(SceneObjectImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	void info(const String& message, bool forcedLog);

	void error(const String& message);

protected:
	String _param0_info__String_bool_;
	String _param0_error__String_;
};

class SceneObjectHelper : public DistributedObjectClassHelper, public Singleton<SceneObjectHelper> {
	static SceneObjectHelper* staticInitializer;

public:
	SceneObjectHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<SceneObjectHelper>;
};

#include "engine/core/ManagedObjectImplementation.h"

class SceneObjectServant : public ManagedObjectImplementation {
public:
	SceneObject* _this;

public:
	SceneObjectServant();
	virtual ~SceneObjectServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*SCENEOBJECT_H_*/
