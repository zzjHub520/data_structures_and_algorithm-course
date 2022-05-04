#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<string> vecstr(num);
    for (int i = 0; i < num; ++i) {
        cin >> vecstr[i];
    }
    vector<unordered_map<char, int>> vecumci(num);
    for (int i = 0; i < num; ++i) {
        for (auto &ele:vecstr[i]) {
            vecumci[i][ele] = ++vecumci[i][ele];
        }
    }
    vector<vector<pair<char, int>>> vecvecpci(num);
    for (int i = 0; i < num; ++i) {
        for (auto &ele:vecumci[i]) {
            vecvecpci[i].emplace_back(ele);
        }
    }
    for (auto &ele_vecpci:vecvecpci) {
        sort(ele_vecpci.begin(), ele_vecpci.end(), [](auto &p1, auto &p2) {
            return p1.second > p2.second;
        });
    }
    for (int i = 0; i < num; ++i) {
        int pretties = 0;
        int pretty = 26;
        for (auto &ele_vecpci:vecvecpci[i]) {
            pretties += pretty * ele_vecpci.second;
            pretty--;
        }
        cout << pretties << endl;
    }


    return 0;
}
