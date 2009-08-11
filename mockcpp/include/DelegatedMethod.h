
#ifndef __MOCKCPP_DELEGATED_METHOD_H
#define __MOCKCPP_DELEGATED_METHOD_H

#include <mockcpp.h>

#include <ArgumentsList.h>
#include <VirtualTable.h>
#include <ChainableMockMethod.h>
#include <ArgumentsMacroHelpers.h>
#include <IndexInvokableGetter.h>

MOCKCPP_NS_START

/////////////////////////////////////////////////////////////////
template <int VPTRIndex, int VTBLIndex, typename ArgumentsList>
struct DelegatedMethod;

/////////////////////////////////////////////////////////////////
#define MOCKCPP_DELEGATED_METHOD_DEF(n) \
template <int VPTRIndex, int VTBLIndex, typename R DECL_TEMPLATE_ARGS(n)> \
struct DelegatedMethod<VPTRIndex, VTBLIndex, ArgumentsList<R DECL_REST_ARGS(n)> > \
{ \
   enum { IsConst = 0 }; \
   enum { NumberOfParameters = n }; \
  \
	R operator()(DECL_PARAMS_LIST(n)) \
   { \
      IndexInvokableGetter* getter = \
                      VirtualTable::getInvokableGetter(this, VPTRIndex); \
      return ChainableMockMethod<R>(getter->getInvokable(VPTRIndex, VTBLIndex)) \
                      ("" DECL_REST_PARAMS(n)); \
   } \
}

/////////////////////////////////////////////////////////////////
#define MOCKCPP_CONST_DELEGATED_METHOD_DEF(n) \
template <int VPTRIndex, int VTBLIndex, typename R DECL_TEMPLATE_ARGS(n)> \
struct DelegatedMethod<VPTRIndex, VTBLIndex, ArgumentsListConst<R DECL_REST_ARGS(n)> > \
{ \
   enum { IsConst = 1 }; \
   enum { NumberOfParameters = n }; \
  \
	R operator()(DECL_PARAMS_LIST(n)) \
   { \
      IndexInvokableGetter* getter = \
                      VirtualTable::getInvokableGetter(this, VPTRIndex); \
      return ChainableMockMethod<R>(getter->getInvokable(VPTRIndex, VTBLIndex)) \
                      ("" DECL_REST_PARAMS(n)); \
   } \
}

/////////////////////////////////////////////////////////////////
#include <DelegatedMethodDef.h>

MOCKCPP_NS_END

#endif
