#include <iostream>
#include <vector>

using namespace std;

int main() {
    string str1 = "nvlrzqcjltmrejybjeshffenvkeqtbsnlocoyaokdpuxutrsmcmoearsgttgyyucgzgcnurfbubgvbwpyslaeykqhaaveqxijc";
    string str2 = "wkigrnngxehuiwxrextitnmjykimyhcbxildpnmrfgcnevjyvwzwuzrwvlomnlogbptornsybimbtnyhlmfecscmojrxekqmj";

    //cin>>str1>>str2;

    int len1 = str1.size();
    int len2 = str2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    pair<int, int> pr{0, 0};
    for (int i = 1; i <= len1; ++i) {
        char c1 = str1[i - 1];
        for (int j = 1; j <= len2; ++j) {
            char c2 = str2[j - 1];
            if (c1 == c2) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (pr.second < dp[i][j]) {
                    if(len1<len2){
                        pr = make_pair(i, dp[i][j]);
                    } else{
                        pr = make_pair(j, dp[i][j]);
                    }
                }
            }
        }
    }

    for (int k = pr.first-pr.second; k < pr.first; ++k) {
        if(len1<len2){
            cout<<str1[k];
        } else{
            cout<<str2[k];
        }

    }
    cout<<endl;

    return 0;
}
