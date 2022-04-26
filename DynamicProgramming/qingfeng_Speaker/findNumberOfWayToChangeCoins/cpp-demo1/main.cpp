#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
vector<vector<T>> initializerV2(int rowNum, int colNum, T value) {
    vector<vector<T>> vecArr(rowNum);
    vector<T> tmp(colNum, value);
    for (int i = 0; i < rowNum; ++i) {
        vecArr[i] = tmp;
    }
    return vecArr;
}

class Solution {
public:
    static int FindTheNumbersOfChangeCoins(vector<int> &coins, int nums) {
        if (coins.empty() || nums == 0) {
            return 0;
        }

        sort(coins.begin(), coins.end());

        int rowNum = coins.size();
        int colNum = nums + 1;

        vector<vector<int>> dp = initializerV2(rowNum, colNum, 0);

        for (int j = 1; j < colNum; ++j) {
            if (j % coins[0] == 0) {
                dp[0][j] = 1;
            }
        }

        for (int i = 0; i < rowNum; ++i) {
            if (dp[i][1] == 1) {
                dp[i][1] = 1;
            }
        }

        for (int i = 0; i < rowNum; ++i) {
            for (int j = 1; j < colNum; ++j) {
                if (j - coins[i] < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else if (j - coins[i] == 0) {
                    dp[i][j] = dp[i - 1][j] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]];
                }
            }
        }
        return dp[rowNum - 1][colNum - 1];
    }
};

int main() {
    vector<int> coins{1, 2, 3};
    int S = 4;
    cout << Solution::FindTheNumbersOfChangeCoins(coins, S) << endl;

    return 0;
}
