/*
 *	server/zone/objects/tangible/surveytool/SurveyTool.cpp generated by engine3 IDL compiler 0.55
 */

#include "SurveyTool.h"

#include "SurveyToolImplementation.h"

#include "../../player/Player.h"

#include "../../creature/CreatureObject.h"

#include "../TangibleObject.h"

/*
 *	SurveyToolStub
 */

SurveyTool::SurveyTool(unsigned long long oid, unsigned int tempCRC, const unicode& n, const string& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new SurveyToolImplementation(oid, tempCRC, n, tempn);
	_impl->_setStub(this);
}

SurveyTool::SurveyTool(CreatureObject* creature, unsigned int tempCRC, const unicode& n, const string& tempn) : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new SurveyToolImplementation(creature, tempCRC, n, tempn);
	_impl->_setStub(this);
}

SurveyTool::SurveyTool(DummyConstructorParameter* param) : TangibleObject(param) {
}

SurveyTool::~SurveyTool() {
}

int SurveyTool::useObject(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addObjectParameter(player);

		return method.executeWithSignedIntReturn();
	} else
		return ((SurveyToolImplementation*) _impl)->useObject(player);
}

int SurveyTool::getSurveyToolType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithSignedIntReturn();
	} else
		return ((SurveyToolImplementation*) _impl)->getSurveyToolType();
}

int SurveyTool::getSamplingToolType() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithSignedIntReturn();
	} else
		return ((SurveyToolImplementation*) _impl)->getSamplingToolType();
}

int SurveyTool::getSurveyToolRange() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithSignedIntReturn();
	} else
		return ((SurveyToolImplementation*) _impl)->getSurveyToolRange();
}

void SurveyTool::setSurveyToolRange(int range) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addSignedIntParameter(range);

		method.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->setSurveyToolRange(range);
}

void SurveyTool::sendSurveyEffect(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->sendSurveyEffect(player);
}

void SurveyTool::sendSampleEffect(Player* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->sendSampleEffect(player);
}

void SurveyTool::surveyRequest(Player* player, string& resourceName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addObjectParameter(player);
		method.addAsciiParameter(resourceName);

		method.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->surveyRequest(player, resourceName);
}

void SurveyTool::sampleRequest(Player* player, string& resourceName) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 14);
		method.addObjectParameter(player);
		method.addAsciiParameter(resourceName);

		method.executeWithVoidReturn();
	} else
		((SurveyToolImplementation*) _impl)->sampleRequest(player, resourceName);
}

/*
 *	SurveyToolAdapter
 */

SurveyToolAdapter::SurveyToolAdapter(SurveyToolImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* SurveyToolAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(useObject((Player*) inv->getObjectParameter()));
		break;
	case 7:
		resp->insertSignedInt(getSurveyToolType());
		break;
	case 8:
		resp->insertSignedInt(getSamplingToolType());
		break;
	case 9:
		resp->insertSignedInt(getSurveyToolRange());
		break;
	case 10:
		setSurveyToolRange(inv->getSignedIntParameter());
		break;
	case 11:
		sendSurveyEffect((Player*) inv->getObjectParameter());
		break;
	case 12:
		sendSampleEffect((Player*) inv->getObjectParameter());
		break;
	case 13:
		surveyRequest((Player*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_surveyRequest__Player_string_));
		break;
	case 14:
		sampleRequest((Player*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_sampleRequest__Player_string_));
		break;
	default:
		return NULL;
	}

	return resp;
}

int SurveyToolAdapter::useObject(Player* player) {
	return ((SurveyToolImplementation*) impl)->useObject(player);
}

int SurveyToolAdapter::getSurveyToolType() {
	return ((SurveyToolImplementation*) impl)->getSurveyToolType();
}

int SurveyToolAdapter::getSamplingToolType() {
	return ((SurveyToolImplementation*) impl)->getSamplingToolType();
}

int SurveyToolAdapter::getSurveyToolRange() {
	return ((SurveyToolImplementation*) impl)->getSurveyToolRange();
}

void SurveyToolAdapter::setSurveyToolRange(int range) {
	return ((SurveyToolImplementation*) impl)->setSurveyToolRange(range);
}

void SurveyToolAdapter::sendSurveyEffect(Player* player) {
	return ((SurveyToolImplementation*) impl)->sendSurveyEffect(player);
}

void SurveyToolAdapter::sendSampleEffect(Player* player) {
	return ((SurveyToolImplementation*) impl)->sendSampleEffect(player);
}

void SurveyToolAdapter::surveyRequest(Player* player, string& resourceName) {
	return ((SurveyToolImplementation*) impl)->surveyRequest(player, resourceName);
}

void SurveyToolAdapter::sampleRequest(Player* player, string& resourceName) {
	return ((SurveyToolImplementation*) impl)->sampleRequest(player, resourceName);
}

/*
 *	SurveyToolHelper
 */

SurveyToolHelper* SurveyToolHelper::staticInitializer = SurveyToolHelper::instance();

SurveyToolHelper::SurveyToolHelper() {
	className = "SurveyTool";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void SurveyToolHelper::finalizeHelper() {
	SurveyToolHelper::finalize();
}

DistributedObject* SurveyToolHelper::instantiateObject() {
	return new SurveyTool(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* SurveyToolHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new SurveyToolAdapter((SurveyToolImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	SurveyToolServant
 */

SurveyToolServant::SurveyToolServant(unsigned long long oid, const unicode& n, const string& tempn, unsigned int tempCRC, int tp) : TangibleObjectImplementation(oid, n, tempn, tempCRC, tp) {
	_classHelper = SurveyToolHelper::instance();
}

SurveyToolServant::SurveyToolServant(CreatureObject* creature, const unicode& n, const string& tempn, unsigned int tempCRC, int tp) : TangibleObjectImplementation(creature, n, tempn, tempCRC, tp) {
	_classHelper = SurveyToolHelper::instance();
}

SurveyToolServant::~SurveyToolServant() {
}

void SurveyToolServant::_setStub(DistributedObjectStub* stub) {
	_this = (SurveyTool*) stub;
	TangibleObjectServant::_setStub(stub);
}

DistributedObjectStub* SurveyToolServant::_getStub() {
	return _this;
}

