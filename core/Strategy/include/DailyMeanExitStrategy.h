#ifndef DAILY_MEAN_EXIT_STRATEGY_H
#define DAILY_MEAN_EXIT_STRATEGY_H

#include <iostream>
#include "IStrategy.h"
#include "TraderState.h"
#include "ShareState.h"

class DailyMeanExitStrategy : public IStrategy {
public:
    DailyMeanExitStrategy() = default;
    ~DailyMeanExitStrategy() override = default;
    void RunStrategy(const TraderState& traderState, const ShareState& shareState) override;
};

#endif