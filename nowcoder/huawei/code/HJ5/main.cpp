#include <iostream>
using namespace std;

int convert(char c1){
    if('0'<=c1&&c1<='9'){
        return c1-'0';
    } else if('A' <=c1&&c1<='Z'){
        return c1-'A'+10;
    }if('a' <=c1&&c1<='z'){
        return c1-'a'+10;
    } else{
        return -1;
    }
}

int main() {
    string hex="0x2C";
    getline(cin,hex);
    int ans=0;
    int scale=1;
    for (int i = hex.size()-1; i >=2; --i) {
        ans+=convert(hex[i])*scale;
        scale*=16;
    }
    cout<<ans<<endl;

    return 0;
}
