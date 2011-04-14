/*
 *	server/zone/managers/resource/ResourceManager.cpp generated by engine3 IDL compiler 0.60
 */

#include "ResourceManager.h"

#include "server/zone/ZoneServer.h"

#include "server/zone/ZoneProcessServer.h"

#include "server/zone/managers/object/ObjectManager.h"

#include "server/zone/objects/player/PlayerCreature.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/resource/ResourceContainer.h"

#include "server/zone/objects/player/sui/listbox/resourcedeedlistbox/ResourceDeedListBox.h"

/*
 *	ResourceManagerStub
 */

enum {RPC_STOP__ = 6,RPC_INITIALIZE__,RPC_SHIFTRESOURCES__,RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_,RPC_SENDRESOURCELISTFORSURVEY__PLAYERCREATURE_INT_STRING_,RPC_SENDSURVEY__PLAYERCREATURE_STRING_,RPC_SENDSAMPLE__PLAYERCREATURE_STRING_STRING_,RPC_HARVESTRESOURCE__PLAYERCREATURE_STRING_INT_,RPC_HARVESTRESOURCETOPLAYER__PLAYERCREATURE_RESOURCESPAWN_INT_,RPC_GETAVAILABLEPOWERFROMPLAYER__PLAYERCREATURE_,RPC_REMOVEPOWERFROMPLAYER__PLAYERCREATURE_INT_,RPC_CREATERESOURCESPAWN__PLAYERCREATURE_STRING_,RPC_GIVEPLAYERRESOURCE__PLAYERCREATURE_STRING_INT_,RPC_GETCURRENTSPAWN__STRING_INT_,RPC_GETRESOURCESPAWN__STRING_,RPC_ADDCHILDRENTODEEDLISTBOX__STRING_RESOURCEDEEDLISTBOX_BOOL_};

ResourceManager::ResourceManager(ZoneServer* server, ZoneProcessServer* impl, ObjectManager* objectMan) : Observer(DummyConstructorParameter::instance()) {
	ResourceManagerImplementation* _implementation = new ResourceManagerImplementation(server, impl, objectMan);
	_impl = _implementation;
	_impl->_setStub(this);
}

ResourceManager::ResourceManager(DummyConstructorParameter* param) : Observer(param) {
}

ResourceManager::~ResourceManager() {
}


void ResourceManager::stop() {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_STOP__);

		method.executeWithVoidReturn();
	} else
		_implementation->stop();
}

void ResourceManager::initialize() {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_INITIALIZE__);

		method.executeWithVoidReturn();
	} else
		_implementation->initialize();
}

void ResourceManager::shiftResources() {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SHIFTRESOURCES__);

		method.executeWithVoidReturn();
	} else
		_implementation->shiftResources();
}

int ResourceManager::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_);
		method.addUnsignedIntParameter(eventType);
		method.addObjectParameter(observable);
		method.addObjectParameter(arg1);
		method.addSignedLongParameter(arg2);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->notifyObserverEvent(eventType, observable, arg1, arg2);
}

void ResourceManager::sendResourceListForSurvey(PlayerCreature* playerCreature, const int toolType, const String& surveyType) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDRESOURCELISTFORSURVEY__PLAYERCREATURE_INT_STRING_);
		method.addObjectParameter(playerCreature);
		method.addSignedIntParameter(toolType);
		method.addAsciiParameter(surveyType);

		method.executeWithVoidReturn();
	} else
		_implementation->sendResourceListForSurvey(playerCreature, toolType, surveyType);
}

void ResourceManager::sendSurvey(PlayerCreature* playerCreature, const String& resname) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDSURVEY__PLAYERCREATURE_STRING_);
		method.addObjectParameter(playerCreature);
		method.addAsciiParameter(resname);

		method.executeWithVoidReturn();
	} else
		_implementation->sendSurvey(playerCreature, resname);
}

void ResourceManager::sendSample(PlayerCreature* playerCreature, const String& resname, const String& sampleAnimation) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SENDSAMPLE__PLAYERCREATURE_STRING_STRING_);
		method.addObjectParameter(playerCreature);
		method.addAsciiParameter(resname);
		method.addAsciiParameter(sampleAnimation);

		method.executeWithVoidReturn();
	} else
		_implementation->sendSample(playerCreature, resname, sampleAnimation);
}

ResourceContainer* ResourceManager::harvestResource(PlayerCreature* player, const String& type, const int quantity) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HARVESTRESOURCE__PLAYERCREATURE_STRING_INT_);
		method.addObjectParameter(player);
		method.addAsciiParameter(type);
		method.addSignedIntParameter(quantity);

		return (ResourceContainer*) method.executeWithObjectReturn();
	} else
		return _implementation->harvestResource(player, type, quantity);
}

void ResourceManager::harvestResourceToPlayer(PlayerCreature* player, ResourceSpawn* resourceSpawn, const int quantity) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_HARVESTRESOURCETOPLAYER__PLAYERCREATURE_RESOURCESPAWN_INT_);
		method.addObjectParameter(player);
		method.addObjectParameter(resourceSpawn);
		method.addSignedIntParameter(quantity);

		method.executeWithVoidReturn();
	} else
		_implementation->harvestResourceToPlayer(player, resourceSpawn, quantity);
}

unsigned int ResourceManager::getAvailablePowerFromPlayer(PlayerCreature* player) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETAVAILABLEPOWERFROMPLAYER__PLAYERCREATURE_);
		method.addObjectParameter(player);

		return method.executeWithUnsignedIntReturn();
	} else
		return _implementation->getAvailablePowerFromPlayer(player);
}

void ResourceManager::removePowerFromPlayer(PlayerCreature* player, unsigned int power) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_REMOVEPOWERFROMPLAYER__PLAYERCREATURE_INT_);
		method.addObjectParameter(player);
		method.addUnsignedIntParameter(power);

		method.executeWithVoidReturn();
	} else
		_implementation->removePowerFromPlayer(player, power);
}

void ResourceManager::getResourceListByType(Vector<ManagedReference<ResourceSpawn* > >& list, int type, String& zoneName) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		throw ObjectNotLocalException(this);

	} else
		_implementation->getResourceListByType(list, type, zoneName);
}

void ResourceManager::createResourceSpawn(PlayerCreature* playerCreature, const String& restype) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_CREATERESOURCESPAWN__PLAYERCREATURE_STRING_);
		method.addObjectParameter(playerCreature);
		method.addAsciiParameter(restype);

		method.executeWithVoidReturn();
	} else
		_implementation->createResourceSpawn(playerCreature, restype);
}

void ResourceManager::givePlayerResource(PlayerCreature* playerCreature, const String& restype, const int quantity) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GIVEPLAYERRESOURCE__PLAYERCREATURE_STRING_INT_);
		method.addObjectParameter(playerCreature);
		method.addAsciiParameter(restype);
		method.addSignedIntParameter(quantity);

		method.executeWithVoidReturn();
	} else
		_implementation->givePlayerResource(playerCreature, restype, quantity);
}

ResourceSpawn* ResourceManager::getCurrentSpawn(const String& restype, int zoneid) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETCURRENTSPAWN__STRING_INT_);
		method.addAsciiParameter(restype);
		method.addSignedIntParameter(zoneid);

		return (ResourceSpawn*) method.executeWithObjectReturn();
	} else
		return _implementation->getCurrentSpawn(restype, zoneid);
}

ResourceSpawn* ResourceManager::getResourceSpawn(const String& spawnName) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETRESOURCESPAWN__STRING_);
		method.addAsciiParameter(spawnName);

		return (ResourceSpawn*) method.executeWithObjectReturn();
	} else
		return _implementation->getResourceSpawn(spawnName);
}

void ResourceManager::addChildrenToDeedListBox(const String& name, ResourceDeedListBox* suil, bool parent) {
	ResourceManagerImplementation* _implementation = (ResourceManagerImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_ADDCHILDRENTODEEDLISTBOX__STRING_RESOURCEDEEDLISTBOX_BOOL_);
		method.addAsciiParameter(name);
		method.addObjectParameter(suil);
		method.addBooleanParameter(parent);

		method.executeWithVoidReturn();
	} else
		_implementation->addChildrenToDeedListBox(name, suil, parent);
}

DistributedObjectServant* ResourceManager::_getImplementation() {

	_updated = true;
	return _impl;
}

void ResourceManager::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	ResourceManagerImplementation
 */

ResourceManagerImplementation::ResourceManagerImplementation(DummyConstructorParameter* param) : ObserverImplementation(param) {
	_initializeImplementation();
}


ResourceManagerImplementation::~ResourceManagerImplementation() {
}


void ResourceManagerImplementation::finalize() {
}

void ResourceManagerImplementation::_initializeImplementation() {
	_setClassHelper(ResourceManagerHelper::instance());

	_serializationHelperMethod();
	_serializationHelperMethod();
}

void ResourceManagerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ResourceManager*) stub;
	ObserverImplementation::_setStub(stub);
}

DistributedObjectStub* ResourceManagerImplementation::_getStub() {
	return _this;
}

ResourceManagerImplementation::operator const ResourceManager*() {
	return _this;
}

void ResourceManagerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ResourceManagerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ResourceManagerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ResourceManagerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ResourceManagerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ResourceManagerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ResourceManagerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ResourceManagerImplementation::_serializationHelperMethod() {
	ObserverImplementation::_serializationHelperMethod();

	_setClassName("ResourceManager");

}

void ResourceManagerImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint16 _varSize = stream->readShort();

		int _currentOffset = stream->getOffset();

		if(ResourceManagerImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool ResourceManagerImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ObserverImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "zoneServer") {
		TypeInfo<ManagedWeakReference<ZoneServer* > >::parseFromBinaryStream(&zoneServer, stream);
		return true;
	}


	return false;
}

void ResourceManagerImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = ResourceManagerImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int ResourceManagerImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	String _name;
	int _offset;
	uint16 _totalSize;
	_name = "zoneServer";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeShort(0);
	TypeInfo<ManagedWeakReference<ZoneServer* > >::toBinaryStream(&zoneServer, stream);
	_totalSize = (uint16) (stream->getOffset() - (_offset + 2));
	stream->writeShort(_offset, _totalSize);


	return 1 + ObserverImplementation::writeObjectMembers(stream);
}

ResourceManagerImplementation::ResourceManagerImplementation(ZoneServer* server, ZoneProcessServer* impl, ObjectManager* objectMan) {
	_initializeImplementation();
	// server/zone/managers/resource/ResourceManager.idl():  		Logger.setLoggingName("ResourceManager");
	Logger::setLoggingName("ResourceManager");
	// server/zone/managers/resource/ResourceManager.idl():  		Logger.setLogging(true);
	Logger::setLogging(true);
	// server/zone/managers/resource/ResourceManager.idl():  		Logger.setGlobalLogging(true);
	Logger::setGlobalLogging(true);
	// server/zone/managers/resource/ResourceManager.idl():  		zoneServer = server;
	zoneServer = server;
	// server/zone/managers/resource/ResourceManager.idl():  		processor = impl;
	processor = impl;
	// server/zone/managers/resource/ResourceManager.idl():  		objectManager = objectMan;
	objectManager = objectMan;
}

/*
 *	ResourceManagerAdapter
 */

ResourceManagerAdapter::ResourceManagerAdapter(ResourceManagerImplementation* obj) : ObserverAdapter(obj) {
}

Packet* ResourceManagerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case RPC_STOP__:
		stop();
		break;
	case RPC_INITIALIZE__:
		initialize();
		break;
	case RPC_SHIFTRESOURCES__:
		shiftResources();
		break;
	case RPC_NOTIFYOBSERVEREVENT__INT_OBSERVABLE_MANAGEDOBJECT_LONG_:
		resp->insertSignedInt(notifyObserverEvent(inv->getUnsignedIntParameter(), (Observable*) inv->getObjectParameter(), (ManagedObject*) inv->getObjectParameter(), inv->getSignedLongParameter()));
		break;
	case RPC_SENDRESOURCELISTFORSURVEY__PLAYERCREATURE_INT_STRING_:
		sendResourceListForSurvey((PlayerCreature*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getAsciiParameter(_param2_sendResourceListForSurvey__PlayerCreature_int_String_));
		break;
	case RPC_SENDSURVEY__PLAYERCREATURE_STRING_:
		sendSurvey((PlayerCreature*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_sendSurvey__PlayerCreature_String_));
		break;
	case RPC_SENDSAMPLE__PLAYERCREATURE_STRING_STRING_:
		sendSample((PlayerCreature*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_sendSample__PlayerCreature_String_String_), inv->getAsciiParameter(_param2_sendSample__PlayerCreature_String_String_));
		break;
	case RPC_HARVESTRESOURCE__PLAYERCREATURE_STRING_INT_:
		resp->insertLong(harvestResource((PlayerCreature*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_harvestResource__PlayerCreature_String_int_), inv->getSignedIntParameter())->_getObjectID());
		break;
	case RPC_HARVESTRESOURCETOPLAYER__PLAYERCREATURE_RESOURCESPAWN_INT_:
		harvestResourceToPlayer((PlayerCreature*) inv->getObjectParameter(), (ResourceSpawn*) inv->getObjectParameter(), inv->getSignedIntParameter());
		break;
	case RPC_GETAVAILABLEPOWERFROMPLAYER__PLAYERCREATURE_:
		resp->insertInt(getAvailablePowerFromPlayer((PlayerCreature*) inv->getObjectParameter()));
		break;
	case RPC_REMOVEPOWERFROMPLAYER__PLAYERCREATURE_INT_:
		removePowerFromPlayer((PlayerCreature*) inv->getObjectParameter(), inv->getUnsignedIntParameter());
		break;
	case RPC_CREATERESOURCESPAWN__PLAYERCREATURE_STRING_:
		createResourceSpawn((PlayerCreature*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_createResourceSpawn__PlayerCreature_String_));
		break;
	case RPC_GIVEPLAYERRESOURCE__PLAYERCREATURE_STRING_INT_:
		givePlayerResource((PlayerCreature*) inv->getObjectParameter(), inv->getAsciiParameter(_param1_givePlayerResource__PlayerCreature_String_int_), inv->getSignedIntParameter());
		break;
	case RPC_GETCURRENTSPAWN__STRING_INT_:
		resp->insertLong(getCurrentSpawn(inv->getAsciiParameter(_param0_getCurrentSpawn__String_int_), inv->getSignedIntParameter())->_getObjectID());
		break;
	case RPC_GETRESOURCESPAWN__STRING_:
		resp->insertLong(getResourceSpawn(inv->getAsciiParameter(_param0_getResourceSpawn__String_))->_getObjectID());
		break;
	case RPC_ADDCHILDRENTODEEDLISTBOX__STRING_RESOURCEDEEDLISTBOX_BOOL_:
		addChildrenToDeedListBox(inv->getAsciiParameter(_param0_addChildrenToDeedListBox__String_ResourceDeedListBox_bool_), (ResourceDeedListBox*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ResourceManagerAdapter::stop() {
	((ResourceManagerImplementation*) impl)->stop();
}

void ResourceManagerAdapter::initialize() {
	((ResourceManagerImplementation*) impl)->initialize();
}

void ResourceManagerAdapter::shiftResources() {
	((ResourceManagerImplementation*) impl)->shiftResources();
}

int ResourceManagerAdapter::notifyObserverEvent(unsigned int eventType, Observable* observable, ManagedObject* arg1, long long arg2) {
	return ((ResourceManagerImplementation*) impl)->notifyObserverEvent(eventType, observable, arg1, arg2);
}

void ResourceManagerAdapter::sendResourceListForSurvey(PlayerCreature* playerCreature, const int toolType, const String& surveyType) {
	((ResourceManagerImplementation*) impl)->sendResourceListForSurvey(playerCreature, toolType, surveyType);
}

void ResourceManagerAdapter::sendSurvey(PlayerCreature* playerCreature, const String& resname) {
	((ResourceManagerImplementation*) impl)->sendSurvey(playerCreature, resname);
}

void ResourceManagerAdapter::sendSample(PlayerCreature* playerCreature, const String& resname, const String& sampleAnimation) {
	((ResourceManagerImplementation*) impl)->sendSample(playerCreature, resname, sampleAnimation);
}

ResourceContainer* ResourceManagerAdapter::harvestResource(PlayerCreature* player, const String& type, const int quantity) {
	return ((ResourceManagerImplementation*) impl)->harvestResource(player, type, quantity);
}

void ResourceManagerAdapter::harvestResourceToPlayer(PlayerCreature* player, ResourceSpawn* resourceSpawn, const int quantity) {
	((ResourceManagerImplementation*) impl)->harvestResourceToPlayer(player, resourceSpawn, quantity);
}

unsigned int ResourceManagerAdapter::getAvailablePowerFromPlayer(PlayerCreature* player) {
	return ((ResourceManagerImplementation*) impl)->getAvailablePowerFromPlayer(player);
}

void ResourceManagerAdapter::removePowerFromPlayer(PlayerCreature* player, unsigned int power) {
	((ResourceManagerImplementation*) impl)->removePowerFromPlayer(player, power);
}

void ResourceManagerAdapter::createResourceSpawn(PlayerCreature* playerCreature, const String& restype) {
	((ResourceManagerImplementation*) impl)->createResourceSpawn(playerCreature, restype);
}

void ResourceManagerAdapter::givePlayerResource(PlayerCreature* playerCreature, const String& restype, const int quantity) {
	((ResourceManagerImplementation*) impl)->givePlayerResource(playerCreature, restype, quantity);
}

ResourceSpawn* ResourceManagerAdapter::getCurrentSpawn(const String& restype, int zoneid) {
	return ((ResourceManagerImplementation*) impl)->getCurrentSpawn(restype, zoneid);
}

ResourceSpawn* ResourceManagerAdapter::getResourceSpawn(const String& spawnName) {
	return ((ResourceManagerImplementation*) impl)->getResourceSpawn(spawnName);
}

void ResourceManagerAdapter::addChildrenToDeedListBox(const String& name, ResourceDeedListBox* suil, bool parent) {
	((ResourceManagerImplementation*) impl)->addChildrenToDeedListBox(name, suil, parent);
}

/*
 *	ResourceManagerHelper
 */

ResourceManagerHelper* ResourceManagerHelper::staticInitializer = ResourceManagerHelper::instance();

ResourceManagerHelper::ResourceManagerHelper() {
	className = "ResourceManager";

	Core::getObjectBroker()->registerClass(className, this);
}

void ResourceManagerHelper::finalizeHelper() {
	ResourceManagerHelper::finalize();
}

DistributedObject* ResourceManagerHelper::instantiateObject() {
	return new ResourceManager(DummyConstructorParameter::instance());
}

DistributedObjectServant* ResourceManagerHelper::instantiateServant() {
	return new ResourceManagerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ResourceManagerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ResourceManagerAdapter((ResourceManagerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

