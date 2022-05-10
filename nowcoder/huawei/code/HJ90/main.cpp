#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main() {
    string ipstr = "255.255.255.1000";
    getline(cin, ipstr);

    regex regIllyal(R"(^(\d|([1-9]\d{1,2}))\.(\d|([1-9]\d{1,2}))\.(\d|([1-9]\d{1,2}))\.(\d|([1-9]\d{1,2}))$)");
    bool flag=regex_match(ipstr,regIllyal);
    if(!flag){
        cout << "NO" << endl;
        return 0;
    }
    regex reg(R"(\.)");
    vector<string> strvec(sregex_token_iterator(ipstr.begin(), ipstr.end(), reg, -1), sregex_token_iterator());

    for (const auto &elestr:strvec) {
        flag = flag && (strtol(elestr.c_str(), nullptr, 10) <= 255);
    }

    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
