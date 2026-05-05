#ifndef BANK_H
#define BANK_H

#include <memory>
#include <vector>
#include <thread>
#include "Trader.h" 

class Bank {
public:
    Bank();
    ~Bank();
    bool RegisterTrader(std::weak_ptr<Trader> trader);
    bool UnregisterTrader(std::weak_ptr<Trader> trader);
private:
    float price;
    std::vector<std::weak_ptr<Trader>> traderList;
    void Notify();
    void UpdatePrice();
    std::thread t;
};

#endif