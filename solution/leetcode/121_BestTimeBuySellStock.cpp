/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction
 * (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *
 * Input: [7, 1, 5, 3, 6, 4]
 * Output: 5
 * max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
 *
 * @author lingjiancong
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        vector<int> margin(prices.size(), 0);
        for (int i = 1, t = prices.size(); i < t; ++i) {
            margin[i] = prices[i] - prices[i - 1];
        }
        int maxPro = 0, curPro = 0;
        for (int i = 1, t = margin.size(); i < t; ++i) {
            int accumulate = margin[i] + curPro;
            if (accumulate > 0) {
                curPro = accumulate;
                if (curPro > maxPro)
                    maxPro = curPro;
            } else
                curPro = 0;
        }
        return maxPro;
    }
};

int main() {
    vector<int> prices({2, 1, 2, 0, 1});
    Solution solution;
    int maxPro = solution.maxProfit(prices);
    cout << maxPro << endl;
}

