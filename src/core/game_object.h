/*!
 * FileName: 	GameObject.h
 * Copyright:	TalosGame Studio Co., Ltd
 * Data: 		2018/07/28 10:35
 * Author: 		miller
 * Desc:		
 */
 
#ifndef __T2D_ENGINE_GAME_OBJECT_H__
#define __T2D_ENGINE_GAME_OBJECT_H__

#include <string>
#include <vector>
#include <typeinfo>
#include "object.h"
#include "component.h"
#include "utility/log/xlog.h"
#include "transform.h"
#include "platform/platform_macros.h"

__T2D_NS_BEGIN__

class GameObject : Object{
public:
	GameObject(const std::string name);
	virtual ~GameObject();

	template <class T>
	T *add_component(){
		const std::type_info &type = typeid(T);
		bool same = std::is_base_of<Component, T>::value;
		if (!same){
			log_error("Cannot add component! Because %s is not inherited component class type!\n", type.name());
			return nullptr;
		}

		if (find_component_by_type(type) != nullptr){
			log_error("%s component already exist!", type.name());
			return nullptr;
		}

		Component *ret = create_component(type);
		TD_ASSERT(ret != nullptr, "Create Component exception!");

		components_.push_back(ret);
		return (T *)ret;
	}

	template <typename T>
	Component *get_component(){
		return find_component_by_type(typeid(T));
	}



private:
	Component *find_component_by_type(const std::type_info &type) const;
	Component *create_component(const std::type_info &type);

public:
	const Transform *transform;

private:
	// compoents of gameObject
	std::vector<Component *> components_;

	std::vector<GameObject*> childs_;
};

__T2D_NS_END__

#endif // __T2D_ENGINE_GAME_OBJECT_H__
