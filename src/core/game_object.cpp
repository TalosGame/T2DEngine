/*!
 * FileName: 	GameObject.cpp
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/28 10:35
 * Author: 		miller
 * Desc:		
 */

#include "game_object.h"
#include "transform.h"
#include "camera.h"

__T2D_NAMESPACE_BEGIN__

GameObject::GameObject(const std::string name) : Object(T2dIdentityType::kAssetObject, name){
	this->transform = add_component<Transform>();
}

GameObject::~GameObject(){
}

Component *GameObject::find_component_by_type(const std::type_info &type)  const{
	for (auto iter = components_.cbegin(); iter != components_.cend(); iter++){
		const std::type_info &t = typeid(**iter);
		if (type == t){
			return *iter;
		}
	}

	return nullptr;
}

Component *GameObject::create_component(const std::type_info &type){
	Component *ret = nullptr;
	if (type == typeid(Transform)){
		ret = new Transform();
	}else if (type == typeid(Camera)){
		ret = new Camera();
	}



	return ret;
}

__T2D_NAMESPACE_END__
