/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and
 * sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time
 * (ie, you must sell the stock before you buy again).
 *
 * @author lingjiancong
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 0) {
            return 0;
        }

        int maxPro = 0, curMin = prices[0], curMax = prices[0];
        for (int i = 1, t = prices.size(); i < t; ++i) {
            if (prices[i] > prices[i - 1]) {
                curMax = prices[i];
            } else {
                maxPro = maxPro + curMax - curMin;
                curMin = curMax = prices[i];
            }
        }
        maxPro = maxPro + curMax - curMin;

        return maxPro;
    }
};

int main() {
    vector<int> vec({1, 2});

    Solution solution;
    cout << solution.maxProfit(vec) << endl;

}
