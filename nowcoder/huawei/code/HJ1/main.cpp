#include <iostream>
#include <vector>
using namespace std;

int main() {

    int i1=-1;
    string str="hello nowcoder";
    getline(cin,str);
    for (int i = 0; i < str.size(); ++i) {
        if(str[i]==' '){
            i1=i;
        }
    }
    cout<<str.size()-1-i1<<endl;

    return 0;
}
