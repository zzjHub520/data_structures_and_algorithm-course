#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string input="Ihave1nose2hands10fingers";
    cin>>input;
    sort(input.begin(),input.end());
    cout<<input;
    return 0;
}
