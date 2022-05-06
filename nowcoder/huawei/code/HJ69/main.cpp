#include <iostream>
#include <vector>

using namespace std;

void print(vector<vector<int>> &C) {
    for (const auto &row:C) {
        for (auto ele:row) {
            cout << ele << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int x, y, z;
    cin >> x >> y >> z;
    vector<vector<int>> A(x, vector<int>(y, 0));
    vector<vector<int>> B(y, vector<int>(z, 0));
    vector<vector<int>> C(x, vector<int>(z, 0));

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < z; ++j) {
            cin >> B[i][j];
        }
    }

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < z; ++j) {
            for (int k = 0; k < y; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    print(C);
    return 0;
}