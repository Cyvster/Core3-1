/*
 *	server/zone/objects/tangible/building/camp/CampObject.cpp generated by engine3 IDL compiler 0.55
 */

#include "CampObject.h"

#include "CampObjectImplementation.h"

#include "../BuildingObject.h"

/*
 *	CampObjectStub
 */

CampObject::CampObject() : BuildingObject(DummyConstructorParameter::instance()) {
	_impl = new CampObjectImplementation();
	_impl->_setStub(this);
}

CampObject::CampObject(DummyConstructorParameter* param) : BuildingObject(param) {
}

CampObject::~CampObject() {
}

/*
 *	CampObjectAdapter
 */

CampObjectAdapter::CampObjectAdapter(CampObjectImplementation* obj) : BuildingObjectAdapter(obj) {
}

Packet* CampObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	CampObjectHelper
 */

CampObjectHelper* CampObjectHelper::staticInitializer = CampObjectHelper::instance();

CampObjectHelper::CampObjectHelper() {
	className = "CampObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void CampObjectHelper::finalizeHelper() {
	CampObjectHelper::finalize();
}

DistributedObject* CampObjectHelper::instantiateObject() {
	return new CampObject(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* CampObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new CampObjectAdapter((CampObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	CampObjectServant
 */

CampObjectServant::CampObjectServant() : BuildingObjectImplementation() {
	_classHelper = CampObjectHelper::instance();
}

CampObjectServant::~CampObjectServant() {
}

void CampObjectServant::_setStub(DistributedObjectStub* stub) {
	_this = (CampObject*) stub;
	BuildingObjectServant::_setStub(stub);
}

DistributedObjectStub* CampObjectServant::_getStub() {
	return _this;
}

