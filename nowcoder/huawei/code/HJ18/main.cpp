#include <iostream>
#include <vector>
#include <regex>
using namespace std;
int main() {
    vector<string> input{"10.70.44.68~255.254.255.0",
                         "1.0.0.1~255.0.0.0",
                         "192.168.0.2~255.255.255.0",
                         "19..0.~255.255.255.0"};
    regex ipreg(R"(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})");
    regex markreg(R"()");
    for(int i=0;i<8;++i){
        cout<<(255<<i)%256<<endl;
    }



    return 0;
}
