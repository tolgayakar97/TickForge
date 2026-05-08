#include "Trader.h"
#include "DailyMeanExitStrategy.h"

Trader::Trader(float budget)
{
    budget_ = budget;
    strategy_ = std::make_unique<DailyMeanExitStrategy>();
}

void Trader::Update(float& price)
{
    std::cout << "Trader notified! Price: " << price << std::endl;
    UpdateTraderState(traderState);
    if(strategy_ != nullptr) {
        //strategy_->RunStrategy();
    }
}

void Trader::SetStrategy(std::unique_ptr<IStrategy> strategy)
{
    strategy_ = std::move(strategy);
}

void Trader::UpdateTraderState(TraderState& traderState)
{
    traderState.budget = budget_;
    traderState.averageCost = averageCost_;
}
