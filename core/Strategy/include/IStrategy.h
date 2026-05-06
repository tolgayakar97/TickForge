#ifndef ISTRATEGY_H
#define ISTRATEGY_H

class IStrategy {
public:
    virtual void RunStrategy(float& price, float& budget, int& transactionAmount) = 0;
    virtual ~IStrategy() = default;
};

#endif