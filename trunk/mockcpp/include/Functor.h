
#ifndef __MOCKCPP_FUNCTOR_H
#define __MOCKCPP_FUNCTOR_H

#include <mockcpp.h>

#include <string>

#include <GlobalMockObject.h>
#include <ArgumentsMacroHelpers.h>

MOCKCPP_NS_START

/////////////////////////////////////////////
class BaseFunctor
{
public:
	BaseFunctor(const std::string& fName)
		: name(fName) {}

	std::string getName() const
	{
		return name;
	}

protected:
	std::string name;
};

////////////////////////////////////////////
template <typename F>
struct Functor;

#define FUNCTOR_CONS()    \
    Functor(const std::string& name) \
      : BaseFunctor(name) \
    {}

////////////////////////////////////////////
#define FUNCTOR_DEF(n) \
template <typename R DECL_TEMPLATE_ARGS(n)> \
struct Functor<R(DECL_ARGS(n))> : public BaseFunctor \
{ \
    FUNCTOR_CONS() \
 \
    R operator()(DECL_PARAMS_LIST(n)) \
    { \
		return ChainableMockMethod<R>(GlobalMockObject::instance.getMethod(name))(DECL_PARAMS(n)); \
    } \
}

// return GlobalMockObject::instance.invoke<R>(getName())(DECL_PARAMS(n));

FUNCTOR_DEF(0);
FUNCTOR_DEF(1);
FUNCTOR_DEF(2);
FUNCTOR_DEF(3);
FUNCTOR_DEF(4);
FUNCTOR_DEF(5);
FUNCTOR_DEF(6);
FUNCTOR_DEF(7);
FUNCTOR_DEF(8);
FUNCTOR_DEF(9);
FUNCTOR_DEF(10);
FUNCTOR_DEF(11);
FUNCTOR_DEF(12);

#if (__GNUC__ && __GNUC__ >= 3)

#define VARDIC_FUNCTOR_DEF(n) \
template <typename R DECL_TEMPLATE_ARGS(n)> \
struct Functor<R(DECL_VARDIC_ARGS(n) ...)> : public BaseFunctor \
{ \
    FUNCTOR_CONS() \
 \
	R operator()(const RefAny& p1 = RefAny(), const RefAny& p2 = RefAny(), \
         const RefAny& p3 = RefAny(), const RefAny& p4 = RefAny(), \
         const RefAny& p5 = RefAny(), const RefAny& p6 = RefAny(), \
         const RefAny& p7 = RefAny(), const RefAny& p8 = RefAny(), \
         const RefAny& p9 = RefAny(), const RefAny& p10 = RefAny(), \
         const RefAny& p11 = RefAny(), const RefAny& p12 = RefAny()) \
    { \
	  return ChainableMockMethod<R>(GlobalMockObject::instance.getMethod(name))(DECL_PARAMS(12)); \
	} \
}

VARDIC_FUNCTOR_DEF(0);
VARDIC_FUNCTOR_DEF(1);
VARDIC_FUNCTOR_DEF(2);
VARDIC_FUNCTOR_DEF(3);
VARDIC_FUNCTOR_DEF(4);
VARDIC_FUNCTOR_DEF(5);
VARDIC_FUNCTOR_DEF(6);
VARDIC_FUNCTOR_DEF(7);
VARDIC_FUNCTOR_DEF(8);

#endif

MOCKCPP_NS_END


#endif

