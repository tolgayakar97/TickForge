#ifndef TRADER_H
#define TRADER_H

#include <iostream>
#include <memory>
#include "IStrategy.h"
#include "TraderState.h"
#include "ShareState.h"

class Trader {
public:
    Trader(float budget);
    ~Trader() = default;
    void Update(const float&);
    void SetStrategy(std::unique_ptr<IStrategy> strategy);
private:
    std::unique_ptr<IStrategy> strategy_;
    float budget_;
    float price_;
    int transactionAmount_;
    int shareAmount_;
    float averageCost_{0.0f};
    TraderState traderState;
    ShareState shareState;
private:
    void UpdateTraderState(TraderState& traderState);
    void UpdateShareState(ShareState& shareState);
    void HandleTransaction(const Signal& signal, int amount);
    void Buy(const int& amount);
    void Sell();
};

#endif