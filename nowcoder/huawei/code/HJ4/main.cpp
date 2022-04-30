#include <iostream>
#include <vector>
using namespace std;

int main() {

    string str = "abc";
    getline(cin, str);
    while (str.size() % 8 != 0) {
        str.push_back('0');
    }
    for(int i=0;i<str.size();i+=8){
        cout<<str.substr(i,8)<<endl;
    }

    return 0;
}
