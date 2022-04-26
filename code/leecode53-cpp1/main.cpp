#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int maxSubArray(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        for (int i = 1; i < len; ++i) {
            dp[i]=max(dp[i-1]+nums[i],nums[i]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << Solution::maxSubArray(nums) << std::endl;
    return 0;
}
