/**
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * Design an algorithm to find the maximum profit. You may complete at most two transactions.
 *
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
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

        int minIndex = 0, minPrice = INT_MAX, maxPro = 0;
        int left = 0, right = 0;

        for (int i = 0, t = prices.size(); i < t; ++i) {

            minIndex = minPrice < prices[i] ? minIndex : i;
            minPrice = minPrice < prices[i] ? minPrice : prices[i];

            if (maxPro < prices[i] - minPrice) {
                maxPro = prices[i] - minPrice;
                left = minIndex;
                right = i;
            }
        }

        int leftPro = maxPro + maxSectionProfit(prices, 0, left);
        int rightPro = maxPro + maxSectionProfit(prices, right, prices.size() - 1);


        maxPro = leftPro > rightPro ? leftPro : rightPro;

        vector<int> minFromRight(prices.begin() + left, prices.begin() + right + 1);
        minPrice = prices[right];


        for (int i = minFromRight.size() - 1; i >= 0; --i) {
            minPrice = minPrice < minFromRight[i] ? minPrice : minFromRight[i];
            minFromRight[i] = minPrice;
        }

        for (int i = left + 1; i < right; ++i) {
            int currentPro = prices[i] - prices[left] - minFromRight[i - left] + prices[right];
            maxPro = currentPro < maxPro ? maxPro : currentPro;
        }

        return maxPro;

    }

private:
    int maxSectionProfit(vector<int>& prices, int start, int end) {

        int minPrice = INT_MAX, maxPro = 0;
        for (int i = start; i <= end; ++i) {
            minPrice = minPrice < prices[i] ? minPrice : prices[i];
            maxPro = maxPro < prices[i] - minPrice ? prices[i] - minPrice : maxPro;
        }
        return maxPro;

    }

};

int main() {
    vector<int> prices({6, 1, 2, 3, 2, 4, 5});
    Solution solution;

    int maxPro = solution.maxProfit(prices);
    cout << maxPro << endl;
}

