#include <iostream>

using namespace std;

bool flag7(int num){
    for (int i = 0; i < 5; ++i) {
        if(num%10==7){
            return true;
        }
        num/=10;
    }
    return false;
}

int main() {
    int num=25;
    cin>>num;
    int count=0;
    for (int i = 7; i <= num; ++i) {
        if(i%7==0){
            count++;
        } else if(flag7(i)){
            count++;
        }
    }
    cout<<count<<endl;

    return 0;
}
