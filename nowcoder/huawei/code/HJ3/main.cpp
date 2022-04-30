#include <iostream>
#include <set>

using namespace std;

int main() {
    set<int> s;
    int tmp;
    int nums = 0;

    cin >> nums;

    for (int i = 0; i < nums; ++i) {
        cin >> tmp;
        s.insert(tmp);
    }
    for (auto &ele:s) {
        cout << ele << endl;
    }


    return 0;
}
