#include "object.h"
#include "utility/log/xlog.h"

uint64 Object::identity_object_count_ = 0;
uint64 Object::identity_asset_count_ = 0;

Object::Object(T2dIdentityType id_type) : identity_type_(id_type){
	this->instance_id_ = Object::generate_id(id_type);
}

Object::Object(T2dIdentityType id_type, const std::string name) : identity_type_(id_type), name_(name){
	this->instance_id_ = Object::generate_id(id_type);
}

uint64 Object::generate_id(T2dIdentityType id_type){
	// Identity max value: 2147483647
	// 1152921504606846975 / 365 / 24 / 60 / 60 / 1000000(obj/¦Ìs) == 36558(year)  That enough!
	uint64 identity_count = (id_type == T2dIdentityType::kAssetObject ? identity_object_count_++ : identity_asset_count_++);
	TD_ASSERT(identity_count < 0xFFFFFFFFFFFFFFF, "Identity out of range");

	uint64 head = (uint64)id_type;
	uint64 ret = (head << 60) | identity_count;
	return ret;
}

Object::~Object(){

}

uint64 Object::instance_id(){
    return this->instance_id_;
}


