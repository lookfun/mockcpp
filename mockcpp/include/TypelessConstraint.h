
#ifndef __MOCKCPP_TYPELESS_CONSTRAINT_H
#define __MOCKCPP_TYPELESS_CONSTRAINT_H

#include <mockcpp.h>
#include <string>

MOCKCPP_NS_START


class TypelessConstraint
{
public:
    virtual ~TypelessConstraint() {}
    virtual bool eval(void) const = 0;
    virtual std::string toString() const = 0;
};

MOCKCPP_NS_END

#endif
