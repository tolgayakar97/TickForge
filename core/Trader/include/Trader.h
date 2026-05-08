#ifndef TRADER_H
#define TRADER_H

#include <iostream>
#include <memory>
#include "IStrategy.h"
#include "TraderState.h"

class Trader {
public:
    Trader(float budget);
    ~Trader() = default;
    void Update(float&);
    void SetStrategy(std::unique_ptr<IStrategy> strategy);
private:
    std::unique_ptr<IStrategy> strategy_;
    float budget_;
    int transactionAmount;
    float averageCost_{0.0f};
    TraderState traderState;
private:
    void UpdateTraderState(TraderState& traderState);
};

#endif