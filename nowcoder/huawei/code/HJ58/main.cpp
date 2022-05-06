#include <iostream>
#include <set>
using namespace std;
int main() {

    multiset<int> ms;
    int n,k;
    int num;
    cin>>n>>k;
    for (int i = 0; i < n; ++i) {
        cin>>num;
        ms.insert(num);
    }
    int i=0;
    for (int m : ms) {
        if(i<k){
            cout<<m<<" ";
        } else{
            break;
        }
        ++i;
    }

    return 0;
}
