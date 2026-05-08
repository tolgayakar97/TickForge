#include "Trader.h"
#include "DailyMeanExitStrategy.h"

Trader::Trader(float budget)
{
    budget_ = budget;
}

void Trader::Update(const float& price)
{
    std::cout << "Trader::Update start" << std::endl;
    price_ = price;
    if (transactionAmount_ == 0) {
        Buy(1); // First buy to set the average cost
        return;
    }

    UpdateTraderState(traderState);
    UpdateShareState(shareState);
    if(strategy_ != nullptr) {
        auto signal = strategy_->RunStrategy(traderState, shareState);
        std::cout << "Signal: " << (signal == Signal::BUY ? "BUY" : "SELL") << std::endl;
        HandleTransaction(signal, 1); // Example: buying 1 share
    }
    std::cout << "Trader::Update end" << std::endl;
}

void Trader::SetStrategy(std::unique_ptr<IStrategy> strategy)
{
    strategy_ = std::move(strategy);
}

void Trader::UpdateTraderState(TraderState& traderState)
{
    traderState.budget = budget_;
    traderState.averageCost = averageCost_;
    traderState.shareAmount = shareAmount_;
}

void Trader::UpdateShareState(ShareState& shareState)
{
    shareState.price = price_;
}

void Trader::HandleTransaction(const Signal& signal, int amount)
{
    if (transactionAmount_ == 4) {
        Sell();
        return;
    }

    if (signal == Signal::BUY && budget_ > price_ * amount) {
        Buy(amount);        
    }
    else if (signal == Signal::SELL && shareAmount_ != 0) {
        Sell();
    }
}

void Trader::Buy(const int& amount)
{
    std::cout << "Trader::Buy start" << std::endl;
    std::cout << "price_ : " << price_ <<std::endl;
    std::cout << "amount : " << amount <<std::endl;
    auto cost = price_ * amount;
    std::cout << "cost : " << cost <<std::endl;
    transactionAmount_++;
    std::cout << "transactionAmount_ : " << transactionAmount_ << std::endl;
        
    budget_ -= cost;
    shareAmount_ += amount;
    averageCost_ = (averageCost_ + cost) /  static_cast<float>(shareAmount_);
    std::cout << "averateCost_ : " << averageCost_ << std::endl;
    std::cout << "shareAmount_ : " << shareAmount_ << std::endl; 
    std::cout << "Trader::Buy end" << std::endl;
}

void Trader::Sell()
{
    auto cost = price_ * shareAmount_;
    budget_ += cost;
    shareAmount_ = 0;
    averageCost_ = 0;
    transactionAmount_++;
    std::cout << "Share sold!" << std::endl;
}
