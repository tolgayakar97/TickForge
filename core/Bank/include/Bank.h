#ifndef BANK_H
#define BANK_H

#include <memory>
#include <vector>
#include <thread>
#include <atomic>
#include "Trader.h" 

class Bank {
public:
    Bank(float p);
    ~Bank();
    void RegisterTrader(std::weak_ptr<Trader>);
    bool UnregisterTrader(std::weak_ptr<Trader>);
private:
    float price;
    std::atomic<bool> stopFlag;
    std::vector<std::weak_ptr<Trader>> traderList;
    void Notify();
    void UpdatePrice();
    void CalculateProfit(int&, float&);
    std::thread t;
};

#endif