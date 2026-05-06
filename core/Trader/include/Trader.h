#ifndef TRADER_H
#define TRADER_H

#include <iostream>
#include <memory>
#include "IStrategy.h"
class Trader
{
public:
    Trader();
    ~Trader() = default;
    void Update(float&);
private:
    std::unique_ptr<IStrategy> strategy_;
    float budget;
    int transactionAmount;
};

#endif