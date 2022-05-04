#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

bool PerfectNum(int num){
    int len=sqrt(num);

    int result=1;
    for (int i = 2; i*i < num; ++i) {
        if(num%i==0){
            result+=i;
            result+=num/i;
        }
    }
    if(len*len==num){
        result+=len;
    }
    return result==num;
}


int main() {

    int n=1000;
    cin>>n;
    int count=0;
    for (int i = 6; i <= n; ++i) {
        if(PerfectNum(i)){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
