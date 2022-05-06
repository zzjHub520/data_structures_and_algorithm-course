#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int num=9876673;
    cin>>num;
    vector<int> ans;
    set<int> s;

    while (num!=0){
        int tmp=num%10;
        if(s.find(tmp)==s.end()){
            s.insert(tmp);
            ans.emplace_back(tmp);
        }
        num/=10;
    }
    for(auto ele:ans){
        cout<<ele;
    }

    return 0;
}
