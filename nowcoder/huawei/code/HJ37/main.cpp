#include <iostream>
#include <vector>
using namespace std;
int main() {
    int inputmonth=5;
    cin>>inputmonth;
    vector<int> vec(inputmonth+1,1);

    for (int i = 3; i <= inputmonth; ++i) {
        vec[i]=vec[i-1]+vec[i-2];
    }
    cout<<vec[inputmonth]<<endl;

    return 0;
}
