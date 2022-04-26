#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int knapsack(vector<int> &p, vector<int> &w, int W) {
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
            if (w[i] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + p[i]);
            }
        }
    }


    for (int i = 0; i < p.size(); ++i) {
        for (int j = 0; j <= W; ++j) {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    int i = (int) p.size() - 1;
    int j = W;
    stack<int> sta;
    while (j != 0) {
        if (dp[i][j] == dp[i - 1][j]) {
            --i;
        } else {
            sta.push(i);
            j = j - w[i];
            --i;
        }
    }

    while (!sta.empty()) {
        cout << sta.top() << " ";
        sta.pop();
    }
    cout << endl;


    return dp[p.size() - 1][W];
}


int main() {
    /**
     * p={11,12,10,26,14,16}
     * w={3,2,2,5,1,3}
     * W=10
     * result=62
     * IND=[2,3,4,5]
     *
     * p={540, 200, 180, 350, 60, 150, 280, 450, 320, 120};
     * w={6, 3, 4, 5, 1, 2, 3, 5, 4, 2}
     * W=30
     * result=2410
     * IND=[1,2,4,6,7,8,9,10]
     * */

    vector<int> p{0, 11, 12, 10, 26, 14, 16};
    vector<int> w{0, 3, 2, 2, 5, 1, 3};
    int W = 10;

//    vector<int> p{0, 540, 200, 180, 350, 60, 150, 280, 450, 320, 120};
//    vector<int> w{0, 6, 3, 4, 5, 1, 2, 3, 5, 4, 2};
//    int W = 30;


    int result = knapsack(p, w, W);
    cout << result << endl;


    return 0;
}
