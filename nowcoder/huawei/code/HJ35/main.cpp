#include <iostream>
#include <vector>

using namespace std;

int main() {

    int input = 8;
    cin >> input;
    vector<vector<int>> vecarr;
    for (int i = input; i > 0; --i) {
        vecarr.emplace_back(vector<int>(i, 1));
    }
    for (int i = 1; i < input; ++i) {
        vecarr[i][0] = vecarr[i - 1][0] + i;
    }
    for (int i = 0; i < input; ++i) {
        for (int j = 1; j < input - i; ++j) {
            vecarr[i][j] = vecarr[i][j - 1] + i + j + 1;
        }
    }

    for (auto &arr:vecarr) {
        for (auto &ele:arr) {
            cout << ele << " ";
        }
        cout << endl;
    }


    return 0;
}
