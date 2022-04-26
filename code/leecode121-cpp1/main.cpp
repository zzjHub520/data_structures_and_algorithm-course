#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        if(prices.empty() || prices.size()==1){
            return 0;
        }

        vector<int> dp(prices.size(),0);
        int minPrice=prices[0];
        for(int i=1;i<prices.size();++i){
            if(prices[i]>minPrice){
                dp[i]=prices[i]-minPrice;
            } else{
                minPrice=prices[i];
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};


int main() {
    vector<int> prices{7,1,5,3,6,4};
    std::cout << Solution::maxProfit(prices) << std::endl;
    return 0;
}
