#include <iostream>

using namespace std;

int main() {
    string str = "ABCabc";
    char c1 = 'A';

    getline(cin, str);
    cin >> c1;

    if ('A' <= c1 && c1 <= 'Z') {
        c1 = c1 - 'A' + 'a';
    }

    int count = 0;
    for (auto &ele:str) {
        if ('A' <= ele && ele <= 'Z') {
            ele = ele - 'A' + 'a';
        }
        if (ele == c1) {
            ++count;
        }
    }
    cout << count << endl;
    return 0;
}
