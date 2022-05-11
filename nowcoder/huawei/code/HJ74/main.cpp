#include <iostream>
#include <regex>
#include <vector>

using namespace std;

int main() {

    string inputstr = R"(xcopy /s c:\\ d:\\e)";
    regex reg(R"("([^"]+))"s + R"("|\S+)");


    getline(cin,inputstr);


    vector<string> strvec(sregex_token_iterator(inputstr.begin(), inputstr.end(), reg, {0}), sregex_token_iterator());
    cout << strvec.size() << endl;
    for (auto elestr:strvec) {
        if (elestr[0] == '"') {
            cout << elestr.substr(1, elestr.size() - 2) << endl;
        } else {
            cout << elestr << endl;
        }
    }

    return 0;
}
