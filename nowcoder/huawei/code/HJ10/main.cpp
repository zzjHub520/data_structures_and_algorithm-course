#include <iostream>
#include <set>
using namespace std;
int main() {

    string str;
    cin>>str;
    set<char> s;
    for(auto &ele:str){
        s.insert(ele);
    }
    cout<<s.size();


    return 0;
}
