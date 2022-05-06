#include <iostream>
#include <vector>
#include <regex>
#include <algorithm>

using namespace std;


int main() {

    string input = "6 cab ad abcd cba abc bca abc 1";
    getline(cin,input);
    regex reg(" ");
    vector<string> vec1(sregex_token_iterator(input.begin(), input.end(), reg, -1),
                        sregex_token_iterator());

    int lenstr = strtol(vec1[0].c_str(), nullptr, 10);
    string str = vec1[lenstr + 1];
    string strget = str;
    sort(strget.begin(), strget.end());
    vector<string> vec2;
    for (int i = 1; i <= lenstr; ++i) {
        string tmpstr = vec1[i];
        sort(tmpstr.begin(), tmpstr.end());
        if(tmpstr==strget && vec1[i]!=str){
            vec2.emplace_back(vec1[i]);
        }
    }
//    for(auto ele:vec2){
//        cout<<ele<<" ";
//    }cout<<endl;
    sort(vec2.begin(),vec2.end());
//    for(auto ele:vec2){
//        cout<<ele<<" ";
//    }cout<<endl;
    cout<<vec2.size()<<endl;
    int len=strtol(vec1.back().c_str(), nullptr, 10);
    if(vec2.size()>=len){
        cout<<vec2[len-1];
    }


    return 0;
}
