/*
 * Behavior.cpp
 *
 *  Created on: Jun 10, 2014
 *      Author: swgemu
 */

#include "Behavior.h"
#include "CompositeBehavior.h"
#include "server/zone/managers/creature/AiMap.h"
#include "LuaBehavior.h"

Behavior::Behavior(AiAgent* _agent, String className) : Object() {
	agent = _agent;
	result = AiMap::SUSPEND;
	parent = NULL;
	interface = AiMap::instance()->getBehavior(className);
}

void Behavior::start() {
	if (!checkConditions()) {
		endWithFailure();
		return;
	}

	result = AiMap::RUNNING;

	if (interface != NULL)
		interface->start(agent);
}

void Behavior::end() {
	if (interface != NULL)
		interface->end(agent);
}

void Behavior::doAction() {
	if (agent->isDead() || agent->isIncapacitated() || (agent->getZone() == NULL)) {
		agent->setFollowObject(NULL);
		return;
	}

	if (!started())
		this->start();
	else if (!checkConditions())
		endWithFailure();

	agent->setCurrentBehavior(this);

	if (finished()) {
		if (parent == NULL) {
			this->end();
			result = AiMap::SUSPEND;
			agent->activateMovementEvent(); // this is an automatic recycle decorator for the root node
		}

		return;
	}

	int res = AiMap::INVALID;
	if (interface != NULL)
		res = interface->doAction(agent);

	switch(res) {
	case AiMap::SUCCESS:
		endWithSuccess();
		break;
	case AiMap::FAILURE:
		endWithFailure();
		break;
	case AiMap::INVALID:
		agent->resetBehaviorList();
		break;
	default:
		break;
	}

	if (!finished() || parent == NULL)
		agent->activateMovementEvent();
}

void Behavior::endWithFailure() {
	this->result = AiMap::FAILURE;
}

void Behavior::endWithSuccess() {
	this->result = AiMap::SUCCESS;
}

void Behavior::endWithError() {
	this->result = AiMap::INVALID;
}

bool Behavior::succeeded() {
	return result == AiMap::SUCCESS;
}

bool Behavior::failed() {
	return result == AiMap::FAILURE;
}

bool Behavior::finished() {
	return result == AiMap::SUCCESS || result == AiMap::FAILURE || result == AiMap::INVALID;
}

bool Behavior::started() {
	return result != AiMap::SUSPEND;
}
