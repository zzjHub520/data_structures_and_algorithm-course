#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> bottleVec;
    int bottleNum;
    cin >> bottleNum;
    while (bottleNum != 0) {
        bottleVec.emplace_back(bottleNum);
        cin >> bottleNum;
    }

    for (auto ele:bottleVec) {
        cout << ele / 2 << endl;
    }
    return 0;
}
