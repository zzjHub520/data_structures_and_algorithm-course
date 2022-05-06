#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int main() {
    string input1 = "10.0.3.193";
    string input2 = "167969729";
    cin>>input1>>input2;

    regex reg(R"(\.)"s);
    vector<string> vec1(sregex_token_iterator(input1.begin(), input1.end(), reg, -1), sregex_token_iterator());
    unsigned int result1 = 0;
    for (int i = 0; i < vec1.size(); ++i) {
        auto uc = (unsigned int) strtol(vec1[i].c_str(), nullptr, 10);
        result1 <<= 8;
        result1 += uc;
    }

    auto scale10 = (unsigned int) strtol(input2.c_str(), nullptr, 10);
    vector<unsigned int> vec2;
    for (int i = 0; i < 4; ++i) {
        auto mid = scale10 % 256;
        vec2.emplace_back(mid);
        scale10 /= 256;
    }
    reverse(vec2.begin(),vec2.end());

    cout<<result1<<endl;

    for(int i=0;i<4;++i){
        cout<<vec2[i];
        if(i!=3){
            cout<<".";
        }
    }

    return 0;
}
