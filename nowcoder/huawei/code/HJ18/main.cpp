#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>
using namespace std;

string mark01(int tmp){
    if(tmp==0){
        return "00000000";
    }
    string str;
    while (tmp!=0){
        str.push_back(tmp%2+'0');
        tmp/=2;
    }
    for(int i=str.size();i<8;++i){
        str.push_back('0');
    }
    reverse(str.begin(),str.end());
    return str;
}

bool mark(string marstr) {
    regex markreg(R"(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})");
    if (!regex_match(marstr, markreg)) {
        return false;
    }
    regex reg(R"(\.)");
    vector<string> marvec(sregex_token_iterator(marstr.begin(), marstr.end(), reg, -1), sregex_token_iterator());
    string str;
    for (int i = 0; i < 4; ++i) {
        int tmp = strtol(marvec[i].c_str(), nullptr, 10);
        str.append(mark01(tmp));
    }
    if(str[0]=='0'||str.back()=='1'){
        return false;
    }

    for(int i=1;i<str.size();++i){
        if(str[i-1]=='0'&&str[i]=='1'){
            return false;
        }
    }
    return true;
}

int main() {
    vector<string> input{"10.70.44.68~255.254.255.0",
                         "1.0.0.1~255.0.0.0",
                         "192.168.0.2~255.255.255.0",
                         "19..0.~255.255.255.0"};
    regex ipreg(R"(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})");
    regex markreg(R"()");
    for (int i = 0; i < 8; ++i) {
        cout << (255 << i) % 256 << endl;
    }

    cout<< mark("255.255.255.0");

    return 0;
}
