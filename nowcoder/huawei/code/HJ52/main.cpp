#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str1 = "abcdefg";
    string str2 = "abcdef";
    cin >> str1 >> str2;
    int len1 = str1.size();
    int len2 = str2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    for (int j = 1; j <= len2; ++j) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= len1; ++i) {
        dp[i][0] = i;
    }


    for (int i = 1; i <= len1; ++i) {
        char c1 = str1[i - 1];
        for (int j = 1; j <= len2; ++j) {
            char c2 = str2[j - 1];
            if (c1 == c2) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    cout << dp[len1][len2];

    return 0;
}
