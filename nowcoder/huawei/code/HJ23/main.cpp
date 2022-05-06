#include <iostream>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    string input = "aabcddd";
    cin >> input;
    map<char, int> m;
    for (auto ele:input) {
        m[ele] = ++m[ele];
    }
    int ansmin = INT_MAX;
    for (auto ele:m) {
        ansmin = min(ansmin, ele.second);
    }
    for (auto ele:m) {
        if (ansmin == ele.second) {
            input.erase(remove(input.begin(), input.end(), ele.first), input.end());
        }
    }
    cout << input << endl;


    return 0;
}
