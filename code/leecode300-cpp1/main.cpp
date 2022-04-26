#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int lengthOfLIS(vector<int> &nums) {
        if(nums.empty()){
            return 0;
        }
        int len=nums.size();
        vector<int> dp(len,1);
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main() {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    cout << Solution::lengthOfLIS(nums) << endl;

    return 0;
}
