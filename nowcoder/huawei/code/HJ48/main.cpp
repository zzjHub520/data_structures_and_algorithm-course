#include <iostream>
#include <list>
using namespace std;
void print(list<int>& ll){

    for(auto ele:ll){
        cout<<ele<<" ";
    }cout<<endl;

}
int main() {
    int num;
    int headnode;
    int delvalue;
    cin>>num>>headnode;
    list<int> ll;
    ll.emplace_back(headnode);

    int nodevalue;
    int value_back;
    for (int i = 1; i < num; ++i) {
        cin>>nodevalue>>value_back;
        for(auto iter=ll.begin();iter!=ll.end();++iter){
            if(*iter==value_back){
                ll.insert(++iter,nodevalue);
                break;
            }
        }
    }
    cin>>delvalue;
    for(auto iter=ll.begin();iter!=ll.end();++iter){
        if(*iter==delvalue){
            ll.erase(iter);
            break;
        }
    }
    print(ll);
    return 0;
}
