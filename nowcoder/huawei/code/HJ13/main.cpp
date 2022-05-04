#include <iostream>
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;

std::vector<std::string> stringSplit(const std::string &str, char delim) {
    std::string s;
    s.push_back(delim);
    std::regex reg(s);
    vector<string> elems(sregex_token_iterator(str.begin(), str.end(), reg, -1), sregex_token_iterator());
    return elems;
}
int main() {

    string str = "I am a boy";
    getline(cin,str);
    vector<string> vecstr(stringSplit(str, ' '));
    reverse(vecstr.begin(),vecstr.end());
    for (auto ele:vecstr) {
        cout << ele << " ";
    }


    return 0;
}
