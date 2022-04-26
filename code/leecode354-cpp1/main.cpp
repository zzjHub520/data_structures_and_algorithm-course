#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxEnvelopes(vector<vector<int>> &envelopes) {
        if(envelopes.empty()){
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), [](const auto e1, const auto e2){
            return e1[0]<e2[0]||(e1[0]==e2[0]&& e1[1]>e2[1]);
        });

        vector<int> dp(envelopes.size(),1);
        for (int i = 1; i < envelopes.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(envelopes[j][1] <envelopes[i][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main() {

    vector<vector<int>> envelopes{{5, 4},
                                  {6, 4},
                                  {6, 7},
                                  {2, 3}};

    std::cout << Solution::maxEnvelopes(envelopes) << std::endl;
    return 0;
}
