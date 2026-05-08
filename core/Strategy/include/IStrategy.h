#ifndef ISTRATEGY_H
#define ISTRATEGY_H

#include "TraderState.h"
#include "ShareState.h"

class IStrategy {
public:
    virtual void RunStrategy(const TraderState& traderState, const ShareState& shareState) = 0;
    virtual ~IStrategy() = default;
};

#endif