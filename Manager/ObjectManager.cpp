#include "ObjectManager.h"
#include "../Object/BaseObject.h"

namespace {
	inline std::vector<BaseObject*> objectList;
}

void ObjectManager::InitManager() {
	for (BaseObject* object : objectList) {
		object->Init();
	}
}

void ObjectManager::UpdateManager() {
	for (BaseObject* object : objectList) {
		if (object->IsAlive()) {
			object->Update();
			object->Draw();
		}
		else {
			RemoveObject(object);
		}
	}
}

void ObjectManager::AddObject(BaseObject* object) {
	objectList.push_back(object);
}

void ObjectManager::RemoveObject(BaseObject* object) {
	std::vector<BaseObject*>& allObj = GetAllObject();
	for (auto itr = allObj.begin(); itr != allObj.end();) {
		if ((*itr) == object) {
			delete *itr;
			itr = allObj.erase(itr);
		}
		else {
			itr++;
		}
	}
}

void ObjectManager::ClearObject() {
	objectList.clear();
}

std::vector<BaseObject*>& ObjectManager::GetAllObject() {
	return objectList;
}
