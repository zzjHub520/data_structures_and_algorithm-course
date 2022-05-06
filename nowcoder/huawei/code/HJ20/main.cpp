#include <iostream>
#include <vector>
#include <set>

using namespace std;

int convert(char c1) {
    if ('A' <= c1 && c1 <= 'Z') {
        return 1;
    } else if ('a' <= c1 && c1 <= 'z') {
        return 2;
    } else if ('0' <= c1 && c1 <= '9') {
        return 3;
    } else {
        return 4;
    }
}

bool repeat(const string &str) {
    for (int j = 0; j < str.size() - 1; ++j) {
        string str1 = str.substr(j, 3);
        for (int k = j + 3; k < str.size() - 1; ++k) {
            string str2 = str.substr(k, 3);
            if (str1 == str2) {
                cout << "NG" << endl;
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<string> input;
    string str;
    while (cin >> str) {
        input.emplace_back(str);
    }

    for (int i = 0; i < input.size(); ++i) {
        if (input[i].size() <= 8) {
            cout << "NG" << endl;
            continue;
        }

        set<int> s;
        for (auto c1:input[i]) {
            s.insert(convert(c1));
        }
        if (s.size() < 3) {
            cout << "NG" << endl;
            continue;
        }

        if (!repeat(input[i])) {
            continue;
        }

        cout << "OK" << endl;


    }


    return 0;
}
