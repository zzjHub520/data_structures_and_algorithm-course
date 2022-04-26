#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int> &prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],-prices[i]);
        }

        return dp[n-1][0];
    }
};


int main() {
    vector<int> prices{1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    std::cout << Solution::maxProfit(prices) << std::endl;
    return 0;
}
