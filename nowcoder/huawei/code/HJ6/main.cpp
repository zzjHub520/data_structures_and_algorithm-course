#include <iostream>
using namespace std;

int main() {
    int num = 0;
    cin >> num;
    //质数因子从2开始，到√num
    for(int i = 2; i * i <= num; i++) {
        if(num % i == 0) {
            cout << i << " ";
            num = num / i;
            i = 1; //因为循环结束会+1，这里重置i为1，下一循环继续从2开始
        }
    }
    cout << num << " ";
    return 0;
}
