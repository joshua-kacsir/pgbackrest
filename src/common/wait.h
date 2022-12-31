/***********************************************************************************************************************************
Wait Handler
***********************************************************************************************************************************/
#ifndef COMMON_WAIT_H
#define COMMON_WAIT_H

/***********************************************************************************************************************************
Wait object
***********************************************************************************************************************************/
typedef struct Wait Wait;

#include "common/time.h"
#include "common/type/object.h"

/***********************************************************************************************************************************
Constructors
***********************************************************************************************************************************/
FV_EXTERN Wait *waitNew(TimeMSec waitTime);

/***********************************************************************************************************************************
Getters/Setters
***********************************************************************************************************************************/
typedef struct WaitPub
{
    TimeMSec remainTime;                                            // Wait time remaining (in usec)
} WaitPub;

// How much time is remaining? Recalculated each time waitMore() is called.
FN_INLINE_ALWAYS TimeMSec
waitRemaining(const Wait *const this)
{
    return THIS_PUB(Wait)->remainTime;
}

/***********************************************************************************************************************************
Functions
***********************************************************************************************************************************/
// Wait and return whether the caller has more time left
FV_EXTERN bool waitMore(Wait *this);

/***********************************************************************************************************************************
Destructor
***********************************************************************************************************************************/
FN_INLINE_ALWAYS void
waitFree(Wait *const this)
{
    objFree(this);
}

/***********************************************************************************************************************************
Macros for function logging
***********************************************************************************************************************************/
#define FUNCTION_LOG_WAIT_TYPE                                                                                                     \
    Wait *
#define FUNCTION_LOG_WAIT_FORMAT(value, buffer, bufferSize)                                                                        \
    objToLog(value, "Wait", buffer, bufferSize)

#endif
