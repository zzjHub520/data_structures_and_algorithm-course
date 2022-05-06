#include <iostream>
#include <algorithm>

using namespace std;

void stablesort(string &str) {
    auto ff = [](const char &c1, const char &c2) {
        char cc1 = c1, cc2 = c2;
        if ('A' <= c1 && c1 <= 'Z') {
            cc1 = c1 - 'A' + 'a';
        }
        if ('A' <= c2 && c2 <= 'Z') {
            cc2 = c2 - 'A' + 'a';
        }
        return cc1 < cc2;
    };

    int length = str.size();
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (ff(str[j + 1], str[j])) {
                char temp;
                temp = str[j + 1];
                str[j + 1] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {

    string input = "A Famous Saying: Much Ado About Nothing (2012/8).";

    getline(cin,input);

    string str1;
    for (auto ele:input) {
        if (('a' <= ele && ele <= 'z') || ('A' <= ele && ele <= 'Z')) {
            str1.push_back(ele);
        }
    }
    stablesort(str1);
    int i=0;
    for(auto &ele:input){
        if (('a' <= ele && ele <= 'z') || ('A' <= ele && ele <= 'Z')) {
            ele=str1[i++];
        }
    }
    cout<<input<<endl;

    return 0;
}
