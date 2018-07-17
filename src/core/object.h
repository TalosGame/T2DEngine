#ifndef __XENGINE_OBJECT_H__
#define __XENGINE_OBJECT_H__

#include <string>

#include "platform/platform_def.h"

class Object
{
public:
    Object();
    Object(const char *name);
    virtual ~Object();

    uint64 instance_id();

private:


protected:
    uint64 instance_id_;
    std::string name_;
};

#endif // __XENGINE_OBJECT_H__
