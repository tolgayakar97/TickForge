#ifndef DAILY_MEAN_EXIT_STRATEGY_H
#define DAILY_MEAN_EXIT_STRATEGY_H

#include <iostream>
#include "IStrategy.h"

class DailyMeanExitStrategy : public IStrategy {
public:
    DailyMeanExitStrategy() = default;
    ~DailyMeanExitStrategy() override = default;
    Signal RunStrategy(const TraderState& traderState, const ShareState& shareState) override;
};

#endif