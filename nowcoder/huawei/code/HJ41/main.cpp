#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> weight(n);
    vector<int> num(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    unordered_set<int> us;
    us.insert(0);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= num[i]; ++j) {
            unordered_set<int> us_tmp(us);
            for (auto ele:us_tmp) {
                us.insert(weight[i] + ele);
            }
        }
    }
    cout << us.size() << endl;

    return 0;
}
