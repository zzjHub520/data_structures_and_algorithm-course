#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    vector<pair<int,int>> vec;
    int num;
    cin>>num;

    for(int i=0;i<num;++i){
        int first,second;
        cin>>first>>second;
        vec.emplace_back(make_pair(first,second));
    }

    map<int,int> m;
    for(auto &ele:vec){
        if(m.find(ele.first)==m.end()){
            m[ele.first]=ele.second;
        } else{
            int tmp=m[ele.first];
            tmp+=ele.second;
            m[ele.first]=tmp;
        }
    }
    for(auto &ele:m){
        cout<<ele.first<<' '<<ele.second<<endl;
    }

    return 0;
}
