// Joel Hernández @ 2023
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <iostream>
#include <limits>
#include <vector>

int max_profit(std::vector<int>& prices) {
    auto lowest = INT_MAX;
    auto highest_profit = 0;

    for (auto i = 0; i < prices.size(); ++i) {
        if (prices[i] < lowest) {
            lowest = prices[i];
        }

        if (auto diff = prices[i] - lowest; highest_profit < diff) {
            highest_profit = diff;
        }
    }

    return highest_profit;
}

int main(void) {
    std::vector<int> prices;
    int current_price;

    while (std::cin >> current_price) {
        prices.push_back(current_price);
    }

    std::cout << max_profit(prices) << std::endl;

    return 0;
}