
#include <InvocationMockerSet.h>
#include <InvocationMocker.h>
#include <Any.h>
#include <Invocation.h>
#include <InvocationId.h>

#include <list>
#include <algorithm>

MOCKCPP_NS_START

namespace {
struct IsIdEqual
{
   bool operator()(InvocationMocker* mocker) const
   {
      const InvocationId* const invId = mocker->getId();
      return invId && invId->getId() == id;
   }

   IsIdEqual(const std::string& identity)
      : id(identity)
   {}

   const std::string& id;
};

void deleteMocker(InvocationMocker* mocker)
{
    delete mocker;
}

void verifyMocker(InvocationMocker* mocker)
{
    mocker->verify();
}

} // namespace

//////////////////////////////////////////////////////////////
InvocationMocker*
InvocationMockerSet::getInvocationMocker(const std::string& id) const
{
   ConstIterator i = find_if( mockers.begin()
                            , mockers.end()
                            , IsIdEqual(id));
   if(i == mockers.end())
      return 0;

   return (*i);
}

//////////////////////////////////////////////////////////////
void
InvocationMockerSet::reset()
{
    for_each(mockers.begin(), mockers.end(), deleteMocker);
    mockers.clear();
}

//////////////////////////////////////////////////////////////
void
InvocationMockerSet::verify()
{
    for_each(mockers.begin(), mockers.end(), verifyMocker);
}

//////////////////////////////////////////////////////////////
void
InvocationMockerSet::addInvocationMocker(InvocationMocker* mocker)
{
    mockers.push_back(mocker);
}

//////////////////////////////////////////////////////////////
std::string
InvocationMockerSet::toString() const
{
    oss_t oss;
    ConstIterator i = mockers.begin();
    for(; i != mockers.end(); i++) {
      oss << (*i)->toString() << "\n\n"; 
    }

    return oss.str();
}

//////////////////////////////////////////////////////////////
Any& 
InvocationMockerSet::invoke(const Invocation& inv
				, SelfDescribe* &resultProvider)
{
    for(Iterator i = mockers.begin(); i != mockers.end(); ++i) {
      if((*i)->matches(inv)) {
        resultProvider = *i;
        return (*i)->invoke(inv);
      }
    }

	return getEmptyAny();
}


MOCKCPP_NS_END
