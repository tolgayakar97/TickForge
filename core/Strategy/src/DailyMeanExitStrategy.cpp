#include <iostream>
#include "DailyMeanExitStrategy.h"

void DailyMeanExitStrategy::RunStrategy(float& price, float& budget, int& transactionAmount) {
    std::cout << "Price: " << price << " Budget: " << budget << " TransactionAmount: " << transactionAmount << std::endl;   
}