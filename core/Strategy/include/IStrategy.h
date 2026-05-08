#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include "TraderState.h"
#include "ShareState.h"
#include "Signal.h"

class IStrategy {
public:
    virtual Signal RunStrategy(const TraderState& traderState, const ShareState& shareState) = 0;
    virtual ~IStrategy() = default;
};

#endif