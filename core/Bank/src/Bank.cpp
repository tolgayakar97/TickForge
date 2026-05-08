#include <iostream>
#include <thread>
#include <chrono>
#include "Bank.h"

Bank::Bank(float p)
{
    stopFlag.store(false, std::memory_order_release);
    price = p;
    t = std::thread(&Bank::UpdatePrice, this);
};

Bank::~Bank()
{
    stopFlag.store(true, std::memory_order_release);
    if (t.joinable())
    {
        t.join();
    }
    std::cout << "Desturctor called!" << std::endl;
};

void Bank::CalculateProfit(int& profitOrLoss, float& price)
{
    srand(time(nullptr));
    auto percentage =  static_cast<float>(rand() % 11);
    percentage = (profitOrLoss  == 1) ? percentage : (-1.0f * percentage); 
    std::cout << "percentage: " << percentage << std::endl;
    std::cout << "old price: " << price << std::endl;
    price += (price * percentage) / 100.0f; 
}

void Bank::UpdatePrice()
{
    while(!stopFlag.load(std::memory_order_acquire)) {
        srand(time(nullptr));
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        auto profitOrLoss = rand() % 2;
        std::cout << "----------------------" << std::endl;
        std::cout << "ProfitOrLoss: " << ((profitOrLoss == 1) ? "Profit" : "Loss") << std::endl;
        CalculateProfit(profitOrLoss, price);
        Notify();
    }
}

void Bank::Notify()
{
    for (auto& trader: traderList) {
        if(auto t = trader.lock()) {
            t->Update(price);
        }
    }
}

void Bank::RegisterTrader(std::weak_ptr<Trader> trader)
{
    traderList.emplace_back(trader);
}