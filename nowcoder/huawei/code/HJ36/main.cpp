#include <iostream>
#include <set>

using namespace std;

int main() {
    string inputkey = "nihao";
    string encrypt = "ni";
    cin>>inputkey>>encrypt;
    set<char> s;
    string actionkey;
    for (auto ele:inputkey) {
        if (s.find(ele) == s.end()) {
            s.insert(ele);
            actionkey.push_back(ele);
        }
    }

    for (int i = 0; i < 26; ++i) {
        char c1 = i + 'a';
        if (s.find(c1) == s.end()) {
            s.insert(c1);
            actionkey.push_back(c1);
        }
    }
    string result;
    for (auto ele:encrypt) {
        result.push_back(actionkey[ele - 'a']);
    }

    cout << result;
    return 0;
}
