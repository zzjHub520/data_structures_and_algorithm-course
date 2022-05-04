#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (maze[0][i] == 0) {
            dp[0][i] = 1;
        } else {
            break;
        }
    }
    for (int i = 1; i < m; ++i) {
        if (maze[i][0] == 0) {
            dp[i][0] = 1;
        } else {
            break;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (maze[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }


    for (const auto &eler:dp) {
        for (auto ele:eler) {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}
