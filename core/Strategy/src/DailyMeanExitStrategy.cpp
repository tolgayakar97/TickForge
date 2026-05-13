#include <iostream>
#include "DailyMeanExitStrategy.h"

Signal DailyMeanExitStrategy::RunStrategy(const TraderState& traderState,
    const ShareState& shareState) {
    std::cout << "shareState.price: " << shareState.price << std::endl;
    std::cout << "traderState.averageCost: " << traderState.averageCost << std::endl;
    std::cout << "traderState.budget: " << traderState.budget << std::endl;
    if(traderState.shareAmount != 0 && (shareState.price >= traderState.averageCost * 1.01f
        || shareState.price <= traderState.averageCost * 0.985f)) {
            return Signal::SELL;
        }
}