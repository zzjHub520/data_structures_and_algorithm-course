#include <iostream>

using namespace std;

int AppleSplit(int m, int n) {
    if (m == 0 || n == 1) {
        return 1;
    }
    int result = 0;
    int lenlimit = (m % n == 0) ? (m / n) : (1 + m / n);
    for (int i = m; i >= lenlimit; --i) {
        result += AppleSplit(min(i, m - i), n - 1);
        if (n == 8)
            cout << i << " " << AppleSplit(min(i, m - i), n - 1) << endl;
    }
    return result;
}

int main() {

    int m = 9;
    int n = 8;
    //cin>>m>>n;
    cout << AppleSplit(m, n);
    return 0;
}
