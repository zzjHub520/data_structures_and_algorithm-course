#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& p, vector<int>& w, int W){
    vector<vector<int>> dp;
    for (int i = 0; i < p.size(); ++i) {
        vector<int> tmp;
        for (int j = 0; j <= W; ++j) {
            tmp.emplace_back(0);
        }
        dp.emplace_back(tmp);
    }

    for (int i = 1; i < p.size(); ++i) {
        for (int j = 1; j <= W; ++j) {
            if(w[i]>j){
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + p[i]);
            }
        }
    }


//    for (int i = 0; i < p.size(); ++i) {
//        for (int j = 0; j <= W; ++j) {
//            cout << dp[i][j] << "\t";
//        }
//        cout << endl;
//    }
    return dp[p.size()-1][W];
}


int main() {
    vector<int> p{0, 540, 200, 180, 350, 60, 150, 280, 450, 320, 120};
    vector<int> w{0, 6, 3, 4, 5, 1, 2, 3, 5, 4, 2};
    int W = 30;

    int result=knapsack(p,w,W);
    cout<<result<<endl;

    return 0;
}
