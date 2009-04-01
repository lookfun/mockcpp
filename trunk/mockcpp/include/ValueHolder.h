
#ifndef __MOCKPP_VALUEHOLDER_H
#define __MOCKPP_VALUEHOLDER_H

#include <mockcpp.h>

#include <Holder.h>

//#include <TypeTraits.h>
#include <EqualityUtil.h>
#include <Formatter.h>

MOCKCPP_NS_START

template<typename ValueType>
class ValueHolder : public Holder<ValueType>
{
public:

    ValueHolder(const ValueType& value)
      : held(value)
    {
    }

    PlaceHolder * clone() const
    { return new ValueHolder(held); }

    const ValueType& getValue() const
    {
      return held;
    }

private:

    ValueType held;
};

MOCKCPP_NS_END


#endif // __MOCKPP_VALUEHOLDER_H


