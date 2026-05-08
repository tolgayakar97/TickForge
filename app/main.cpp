#include <iostream>
#include <chrono>
#include <memory>
#include "Bank.h"
#include "Trader.h"
#include "DailyMeanExitStrategy.h"

int main()
{
    Bank bank(50.0f);
    auto trader = std::make_shared<Trader>(500.0f);
    bank.RegisterTrader(trader);

    auto strategy = std::make_unique<DailyMeanExitStrategy>();
    trader->SetStrategy(std::move(strategy));
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}