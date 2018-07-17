#include "object.h"

Object::Object(){
    instance_id_++;
}

Object::Object(const char *name) : name_(name){
    this->instance_id_++;
}

Object::~Object(){

}

uint64 Object::instance_id(){
    return this->instance_id_;
}
