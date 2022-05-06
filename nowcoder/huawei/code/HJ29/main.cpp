#include <iostream>

using namespace std;

char ChangeCase(char c1) {
    if ('a' <= c1 && c1 <= 'z') {
        return c1 - 'a' + 'A';
    } else if ('A' <= c1 && c1 <= 'Z') {
        return c1 + 'a' - 'A';
    } else {
        exit(-1);
    }
}

char EncryptChar(char c1) {
    if (('a' <= c1 && c1 <= 'y') || ('A' <= c1 && c1 <= 'Y')) {
        return ChangeCase(c1+1);
    } else if(c1=='z'||c1=='Z'){
        if(c1=='z'){
            return 'A';
        } else{
            return 'a';
        }
    } else if(('0'<=c1&&c1<='8')){
        return c1+1;
    } else if(c1=='9'){
        return '0';
    } else{
        return c1;
    }
}

char DencryptChar(char c1){
    if (('b' <= c1 && c1 <= 'z') || ('B' <= c1 && c1 <= 'Z')) {
        return ChangeCase(c1-1);
    } else if(c1=='a'||c1=='A'){
        if(c1=='A'){
            return 'z';
        } else{
            return 'Z';
        }
    } else if(('1'<=c1&&c1<='9')){
        return c1-1;
    } else if(c1=='0'){
        return '9';
    } else{
        return c1;
    }
}

int main() {
    string tobeEncrypt1 = "2OA92AptLq5G1lW8564qC4nKMjv8C";
    string tobeDecrypt2 = "B5WWIj56vu72GzRja7j5";

    getline(cin,tobeEncrypt1);
    getline(cin,tobeDecrypt2);

    for(auto &ele:tobeEncrypt1){
        ele=EncryptChar(ele);
    }
    cout<<tobeEncrypt1<<endl;
    for(auto &ele:tobeDecrypt2){
        ele=DencryptChar(ele);
    }
    cout<<tobeDecrypt2<<endl;
    return 0;
}
