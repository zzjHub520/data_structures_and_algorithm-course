#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int> &prices) {
        if (prices.empty() || prices.size() == 1) {
            return 0;
        }

        //vector<int> dp(prices.size(), 0);
        int profit = 0;
        int minPrice = prices[0];
        int maxPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if(prices[i-1]<=prices[i]){
                maxPrice=prices[i];
            } else{
                profit+=maxPrice-minPrice;
                minPrice=prices[i];
                maxPrice=prices[i];
            }
        }
        profit+=maxPrice-minPrice;

        return profit;
    }
    static int maxProfit1(vector<int> &prices) {
        if (prices.empty() || prices.size() == 1) {
            return 0;
        }

        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1]);
        }

        return dp[prices.size()-1][0];
    }
    static int maxProfit2(vector<int> &prices) {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};


int main() {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    std::cout << Solution::maxProfit2(prices) << std::endl;
    return 0;
}
