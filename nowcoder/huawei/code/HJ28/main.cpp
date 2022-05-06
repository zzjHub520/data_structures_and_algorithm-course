#include <iostream>
#include <vector>

using namespace std;

bool prime(int num) {
    if (num < 2) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    if(num%2==0){
        return false;
    }
    for (int i = 3; i * i < num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    int n = 4;
    vector<int> vecarr{2, 5, 6, 13};
    int count = 0;
    for (int i = 0; i < vecarr.size() - 1; ++i) {
        for (int j = i + 1; j < vecarr.size(); ++j) {
            int tmp = vecarr[i] + vecarr[j];
            int flag = prime(tmp);
            if (flag) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
