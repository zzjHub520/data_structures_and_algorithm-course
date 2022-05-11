#include <iostream>
#include <vector>
using namespace std;

int main() {

    int num;
    vector<int> result;
    while (cin >> num) {
        int count = 0;
        while (num != 0) {
            if (num % 2 == 1) {
                count++;
            }
            num /= 2;
        }
        result.emplace_back(count);
    }

    for(auto ele:result){
        cout<<ele<<endl;
    }

    return 0;
}
