#include <iostream>

using namespace std;

int main() {

    int inputhigh = 1;
    cin>>inputhigh;
    double newhigh=inputhigh;
    double path = inputhigh;

    for (int i = 1; i < 5; ++i) {
        path+=newhigh;
        newhigh=newhigh/2;
    }
    cout<<path<<endl;
    cout<<newhigh/2<<endl;


    return 0;
}
