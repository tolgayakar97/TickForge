#include <thread>
#include <chrono>
#include "Bank.h"

Bank::Bank()
{
    price = 0.0f;
    t = std::thread(&Bank::UpdatePrice, this);
};

Bank::~Bank()
{
    if (t.joinable())
    {
        t.join();
    }
};

void Bank::UpdatePrice()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}