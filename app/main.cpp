#include <iostream>
#include <chrono>
#include <memory>
#include "Bank.h"
#include "Trader.h"

int main()
{
    Bank b(100.0f);
    auto trader = std::make_shared<Trader>();
    b.RegisterTrader(trader);
    std::this_thread::sleep_for(std::chrono::seconds(10));
    return 0;
}