#include <iostream>
#include <regex>
#include <vector>

using namespace std;

vector<string> stringSplit(string input, char delim) {
    string str;
    str.push_back(delim);
    regex reg(str);
    vector<string> result(sregex_token_iterator(input.begin(), input.end(), reg, -1), sregex_token_iterator());
    return result;
}

int main() {

    string input = "A10;S20;W10;D30;X;A1A;B10A11;;A10;";
    cin>>input;
    vector<string> vecarr(stringSplit(input, ';'));
    int x = 0;
    int y = 0;
    regex reg(R"([AWSD]\d{1,2})");
    for (int i = 0; i < vecarr.size(); ++i) {
        if (regex_match(vecarr[i], reg)) {
            switch (vecarr[i][0]) {
                case 'A':
                    x -= strtol(vecarr[i].substr(1).c_str(), nullptr, 10);
                    continue;
                case 'D':
                    x += strtol(vecarr[i].substr(1).c_str(), nullptr, 10);
                    continue;
                case 'S':
                    y -= strtol(vecarr[i].substr(1).c_str(), nullptr, 10);
                    continue;
                case 'W':
                    y += strtol(vecarr[i].substr(1).c_str(), nullptr, 10);
                    continue;
                default:
                    cout << "swith error!" << endl;
            }
        }
    }
    cout<<x<<","<<y;

    return 0;
}
