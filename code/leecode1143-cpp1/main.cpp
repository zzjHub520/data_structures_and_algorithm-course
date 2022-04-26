#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    static int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        if (m == 0 || n == 0) {
            return 0;
        }
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; ++i) {
            char c1 = text1[i - 1];
            for (int j = 1; j <= n; ++j) {
                char c2 = text2[j - 1];
                if(c1==c2){
                    dp[i][j]=dp[i-1][j-1]+1;
                } else{
                    dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

int main() {

    string text1 = "abcde";
    string text2 = "ace";
    cout << Solution::longestCommonSubsequence(text1, text2) << endl;

    return 0;
}
