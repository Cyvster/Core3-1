/*
 *	server/zone/objects/tangible/tool/smuggler/PrecisionLaserKnife.h generated by engine3 IDL compiler 0.60
 */

#ifndef PRECISIONLASERKNIFE_H_
#define PRECISIONLASERKNIFE_H_

#include "engine/core/Core.h"

#include "engine/core/ManagedReference.h"

#include "engine/core/ManagedWeakReference.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {

class TangibleObject;

} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible;

namespace server {
namespace zone {
namespace objects {
namespace scene {

class SceneObject;

} // namespace scene
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::scene;

namespace server {
namespace zone {

class Zone;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace packets {
namespace scene {

class AttributeListMessage;

} // namespace scene
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::scene;

namespace server {
namespace zone {
namespace packets {
namespace object {

class ObjectMenuResponse;

} // namespace object
} // namespace packets
} // namespace zone
} // namespace server

using namespace server::zone::packets::object;

namespace server {
namespace zone {
namespace objects {
namespace player {

class PlayerCreature;

} // namespace player
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::player;

namespace server {
namespace zone {

class ZoneServer;

} // namespace zone
} // namespace server

using namespace server::zone;

namespace server {
namespace zone {
namespace objects {
namespace manufactureschematic {

class ManufactureSchematic;

} // namespace manufactureschematic
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::manufactureschematic;

#include "server/zone/objects/player/PlayerObject.h"

#include "server/zone/objects/manufactureschematic/craftingvalues/CraftingValues.h"

#include "server/zone/objects/tangible/tool/smuggler/SlicingTool.h"

#include "engine/lua/LuaObject.h"

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tool {
namespace smuggler {

class PrecisionLaserKnife : public SlicingTool {
public:
	PrecisionLaserKnife();

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void updateCraftingValues(ManufactureSchematic* schematic);

	void updateCharges(int val);

	void useCharge(PlayerCreature* player);

	int getCharges();

	DistributedObjectServant* _getImplementation();

	void _setImplementation(DistributedObjectServant* servant);

protected:
	PrecisionLaserKnife(DummyConstructorParameter* param);

	virtual ~PrecisionLaserKnife();

	friend class PrecisionLaserKnifeHelper;
};

} // namespace smuggler
} // namespace tool
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::tool::smuggler;

namespace server {
namespace zone {
namespace objects {
namespace tangible {
namespace tool {
namespace smuggler {

class PrecisionLaserKnifeImplementation : public SlicingToolImplementation {
protected:
	int charges;

public:
	PrecisionLaserKnifeImplementation();

	PrecisionLaserKnifeImplementation(DummyConstructorParameter* param);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void fillAttributeList(AttributeListMessage* msg, PlayerCreature* object);

	void updateCraftingValues(ManufactureSchematic* schematic);

	void updateCharges(int val);

	void useCharge(PlayerCreature* player);

	int getCharges();

	PrecisionLaserKnife* _this;

	operator const PrecisionLaserKnife*();

	DistributedObjectStub* _getStub();
	virtual void readObject(ObjectInputStream* stream);
	virtual void writeObject(ObjectOutputStream* stream);
protected:
	virtual ~PrecisionLaserKnifeImplementation();

	void finalize();

	void _initializeImplementation();

	void _setStub(DistributedObjectStub* stub);

	void lock(bool doLock = true);

	void lock(ManagedObject* obj);

	void rlock(bool doLock = true);

	void wlock(bool doLock = true);

	void wlock(ManagedObject* obj);

	void unlock(bool doLock = true);

	void runlock(bool doLock = true);

	void _serializationHelperMethod();
	bool readObjectMember(ObjectInputStream* stream, const String& name);
	int writeObjectMembers(ObjectOutputStream* stream);

	friend class PrecisionLaserKnife;
};

class PrecisionLaserKnifeAdapter : public SlicingToolAdapter {
public:
	PrecisionLaserKnifeAdapter(PrecisionLaserKnifeImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	int handleObjectMenuSelect(PlayerCreature* player, byte selectedID);

	void updateCraftingValues(ManufactureSchematic* schematic);

	void updateCharges(int val);

	void useCharge(PlayerCreature* player);

	int getCharges();

};

class PrecisionLaserKnifeHelper : public DistributedObjectClassHelper, public Singleton<PrecisionLaserKnifeHelper> {
	static PrecisionLaserKnifeHelper* staticInitializer;

public:
	PrecisionLaserKnifeHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectServant* instantiateServant();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class Singleton<PrecisionLaserKnifeHelper>;
};

} // namespace smuggler
} // namespace tool
} // namespace tangible
} // namespace objects
} // namespace zone
} // namespace server

using namespace server::zone::objects::tangible::tool::smuggler;

#endif /*PRECISIONLASERKNIFE_H_*/
