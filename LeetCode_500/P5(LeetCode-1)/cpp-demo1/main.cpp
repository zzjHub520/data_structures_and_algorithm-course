#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mapNums;
        unordered_map<int, int>::iterator it;
        vector<int> vec;
        for (int i = 0; i < nums.size(); ++i) {
            int another = target - nums[i];
            it = mapNums.find(another);
            if (it != mapNums.end()) {
                vec.push_back(it->second);
                vec.push_back(i);
                break;
            } else {
                mapNums.emplace(nums[i], i);
            }
        }
        int a=INT_MAX;
        return vec;
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    Solution solution;
    vector<int> result = solution.twoSum(nums, target);
    for (auto ele:result) {
        cout << ele << endl;
    }
    return 0;
}
