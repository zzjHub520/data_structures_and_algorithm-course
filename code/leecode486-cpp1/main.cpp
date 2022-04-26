#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    static int game(vector<int> nums, bool flag){
        if(nums.size()==1){
            if(flag){
                return nums.back();
            } else{
                return 0;
            }
        }

        flag=!flag;
        int maxans=max(game()+nums.front(),nums.back());
    }

    static bool PredictTheWinner(vector<int> &nums) {
        return game(nums,true);
    }
};

int main() {
    vector<int> nums{1, 5, 233, 7};
    std::cout << Solution::PredictTheWinner(nums) << std::endl;
    return 0;
}
