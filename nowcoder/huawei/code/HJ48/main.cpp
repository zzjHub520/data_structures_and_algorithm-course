#include <iostream>
#include <list>
using namespace std;
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
        
    }


    return 0;
}
