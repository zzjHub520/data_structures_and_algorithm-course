#include <iostream>
#include <regex>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string input = "$bo*y gi!r#l";
    getline(cin, input);
    for (auto &ele:input) {
        if (!('a' <= ele && ele <= 'z' || 'A' <= ele && ele <= 'Z')) {
            ele = ' ';
        }
    }

    regex reg(" ");
    vector<string> vec1(sregex_token_iterator(input.begin(), input.end(), reg, -1), sregex_token_iterator());
    reverse(vec1.begin(), vec1.end());
    for (auto &ele:vec1) {
        cout << ele << " ";
    }


    return 0;
}
