#include <iostream>
#include <set>
using namespace std;
int main() {

    int num;
    cin>>num;
    multiset<string> s;
    for(int i=0;i<num;++i){
        string tmp;
        cin>>tmp;
        s.insert(tmp);
    }
    for(auto &ele:s){
        cout<<ele<<endl;
    }

    return 0;
}
