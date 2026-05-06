#include <iostream>
#include "Trader.h"

Trader::Trader() {};
void Trader::Update(float& price)
{
    std::cout << "Trader notified! Price: " << price << std::endl;
}

