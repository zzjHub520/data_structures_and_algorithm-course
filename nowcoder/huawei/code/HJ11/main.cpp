#include <iostream>
#include <algorithm>
using namespace std;

string intostr(int num){
    string str;
    if(num==0){
        return "0";
    }
    while (num!=0){
        str.push_back(num%10+'0');
        num/=10;
    }
    return str;
}

int main() {

    int num=1516000;
    cin>>num;
    cout<<intostr(num);

    return 0;
}
