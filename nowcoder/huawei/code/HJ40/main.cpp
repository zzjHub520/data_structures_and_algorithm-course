#include <iostream>
#include <map>
using namespace std;

int convert(char c1){
    if('a'<=c1&&c1<='z'||'A'<=c1&&c1<='Z'){
        return 1;
    } else if(c1==' '){
        return 2;
    } else if('0'<=c1&&c1<='9'){
        return 3;
    } else{
        return 4;
    }
}

int main() {

    string input=R"(1qazxsw23 edcvfr45tgbn hy67uj m,ki89ol.\\/;p0-=\\][)";
    getline(cin,input);
    map<int,int> m;
    int ii;
    for(auto c1:input){
        ii=convert(c1);
        m[ii]=++m[ii];
    }
    cout<<m[1]<<endl;
    cout<<m[2]<<endl;
    cout<<m[3]<<endl;
    cout<<m[4]<<endl;

    return 0;
}
