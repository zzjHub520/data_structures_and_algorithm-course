#include <iostream>

using namespace std;

char lowerconvert(char c1) {
    if ('a' <= c1 && c1 <= 'c') {
        return '2';
    } else if ('d' <= c1 && c1 <= 'f') {
        return '3';
    } else if ('g' <= c1 && c1 <= 'i') {
        return '4';
    } else if ('j' <= c1 && c1 <= 'l') {
        return '5';
    } else if ('m' <= c1 && c1 <= 'o') {
        return '6';
    } else if ('p' <= c1 && c1 <= 's') {
        return '7';
    } else if ('t' <= c1 && c1 <= 'v') {
        return '8';
    } else {
        return '9';
    }
}

char capitalconvert(char c1) {
    if (c1 == 'Z') {
        return 'a';
    } else {
        return c1 - 'A' + 'b';
    }
}

int main() {

    string input;
    cin>>input;
    string result;
    for(auto ele:input){
        if('a' <= ele && ele <= 'z'){
            result.push_back(lowerconvert(ele));
        } else if('A' <= ele && ele <= 'Z'){
            result.push_back(capitalconvert(ele));
        } else{
            result.push_back(ele);
        }
    }
    cout<<result;
    return 0;
}
