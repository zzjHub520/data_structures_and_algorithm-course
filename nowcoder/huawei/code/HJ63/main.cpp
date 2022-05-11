#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl << "-------------" << endl;
}

int main() {
    string inputstr = "AACTGTGCACGACCTGA";
    int num = 5;
    cin>>inputstr>>num;
    vector<int> vec;
    int count = 0;
    for (int i = 0; i < num; ++i) {
        if ('C' == inputstr[i] || 'G' == inputstr[i]) {
            count++;
        }
    }
    vec.emplace_back(count);
    //print(vec);
    if (inputstr.size() != num) {
        for (int i = 1; i < inputstr.size() - num; ++i) {
            if ('C' == inputstr[i - 1] || 'G' == inputstr[i - 1]) {
                count--;
            }
            if ('C' == inputstr[i + num - 1] || 'G' == inputstr[i + num - 1]) {
                count++;
            }
            vec.emplace_back(count);
            //print(vec);
        }
    }
    int mratio = 0;
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[mratio] < vec[i]) {
            mratio = i;
        }
    }

    for (int j = mratio; j < mratio + num; ++j) {
        cout << inputstr[j];
    }


    return 0;
}
