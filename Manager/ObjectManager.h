#pragma once
#include <vector>
#include "../Object/BaseObject.h"

namespace {}

namespace ObjectManager {

	void InitManager();
	void UpdateManager();
	void AddObject(BaseObject* object);
	void RemoveObject(BaseObject* object);
	void ClearObject();
	std::vector<BaseObject*>& GetAllObject();

	template<typename T>
	T FindObject() {
		for (BaseObject* obj : GetAllObject()) {
			if (obj == nullptr) continue;
			if (!obj->IsAlive()) continue;
			T object = dynamic_cast<T>(obj);
			if (object != nullptr) {
				return object;
			}
		}
		return nullptr;
	}

	template<typename T>
	std::vector<T> FindObjectList() {
		std::vector<BaseObject*> objList;
		for (BaseObject* obj : GetAllObject()) {
			if (obj == nullptr) continue;
			if (!obj->IsAlive()) continue;
			T object = dynamic_cast<T>(obj);
			if (object != nullptr) {
				objList.push_back(object);
			}
		}
		return objList;
	}
}