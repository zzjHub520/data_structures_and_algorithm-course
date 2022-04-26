#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int maxProduct(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        vector<int> maxTmp(nums), minTmp(nums);
        for(int i=1; i<nums.size();++i){
            maxTmp[i]=max(maxTmp[i-1]*nums[i],max(nums[i],minTmp[i-1]*nums[i]));
            minTmp[i]=min(minTmp[i-1]*nums[i],min(nums[i],maxTmp[i-1]*nums[i]));
        }
        return *max_element(maxTmp.begin(), maxTmp.end());

    }
};

int main() {
    vector<int> nums{2,3,-2,4};
    std::cout << Solution::maxProduct(nums) << std::endl;
    return 0;
}
