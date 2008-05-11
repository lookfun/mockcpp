
#include <TypelessStubAdapter.h>
#include <TypelessStub.h>
#include <Any.h>

MOCKCPP_NS_START

////////////////////////////////////////////////////////
TypelessStubAdapter::TypelessStubAdapter(TypelessStub* ts)
		: stub(ts)
{}

////////////////////////////////////////////////////////
TypelessStubAdapter::~TypelessStubAdapter()
{
	delete stub;
}
////////////////////////////////////////////////////////
Any& TypelessStubAdapter::invoke(const Invocation& inv)
{
	return stub->invoke();
}

////////////////////////////////////////////////////////
std::string TypelessStubAdapter::toString() const
{
   return stub->toString();
}

////////////////////////////////////////////////////////

MOCKCPP_NS_END


