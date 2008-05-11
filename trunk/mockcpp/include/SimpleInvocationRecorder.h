
#ifndef __MOCKCPP_SIMPLE_INVOCATION_RECORDER_H
#define __MOCKCPP_SIMPLE_INVOCATION_RECORDER_H

#include <mockcpp.h>
#include <InvokedTimesRecorder.h>

MOCKCPP_NS_START

class SimpleInvocationRecorder
      : public InvokedTimesRecorder
{
public:

    SimpleInvocationRecorder();

    unsigned int getInvokedTimes() const;

    void increaseInvoked();

protected:

    unsigned int invokedTimes;
};

MOCKCPP_NS_END

#endif

