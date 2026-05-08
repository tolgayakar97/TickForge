#include <iostream>
#include "DailyMeanExitStrategy.h"

Signal DailyMeanExitStrategy::RunStrategy(const TraderState& traderState,
    const ShareState& shareState) {
    std::cout << "DailyMeanExitStrategy::RunStrategy start" << std::endl;
    std::cout << "*****************************************" << std::endl;
    std::cout << "shareState.price: " << shareState.price << std::endl;
    std::cout << "traderState.averageCost: " << traderState.averageCost << std::endl;
    std::cout << "traderState.budget: " << traderState.budget << std::endl;
    if(traderState.shareAmount != 0 && (shareState.price >= traderState.averageCost * 1.01f
        || shareState.price <= traderState.averageCost * 0.985f)) {
            std::cout << "*****************************************" << std::endl;
            std::cout << "DailyMeanExitStrategy::RunStrategy end" << std::endl;
            return Signal::SELL;
        }
    std::cout << "*****************************************" << std::endl;
    std::cout << "DailyMeanExitStrategy::RunStrategy end" << std::endl;
    return Signal::BUY;
}