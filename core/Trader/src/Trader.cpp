#include "Trader.h"
#include "DailyMeanExitStrategy.h"

Trader::Trader()
{
    float budget = 100.0f;
    int transactionAmount = 0;
    strategy_ = std::make_unique<DailyMeanExitStrategy>();
}

void Trader::Update(float& price)
{
    std::cout << "Trader notified! Price: " << price << std::endl;
    strategy_->RunStrategy(price, budget, transactionAmount);
}

