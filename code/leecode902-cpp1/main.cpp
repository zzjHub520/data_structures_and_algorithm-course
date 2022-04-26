#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    static string digits2hexstring(vector<string> &digits, int numtmp) {
        //digits.emplace(digits.begin(), "*");
        int scale = digits.size();
        stack<int> sta;
        while (numtmp != 0) {
            sta.push(numtmp % scale);
            numtmp /= scale;
        }
        string str;
        while (!sta.empty()) {
            string stmp = digits[sta.top()];
            sta.pop();
            str += stmp;
        }
        return str;
    }


    static int atMostNGivenDigitSet(vector<string> &digits, int n) {
        int numder = 0;
        int i = 1;
        int count = 0;
        vector<string> digits1=digits;
        digits1.emplace(digits1.begin(),"*");
        while (true) {
            string strtmp = digits2hexstring(digits1, i);
            if (strtmp.find('*') == string::npos) {
                numder = strtol(strtmp.c_str(), nullptr, 10);
                if (numder > n) {
                    break;
                }
                ++count;
                //cout << strtmp << "\t";
            }
            ++i;
        }
        //cout << endl << endl;
        return count;
    }
};

int main() {
    vector<string> digits{"1", "3", "5", "7"};
    int n = 100;
    std::cout << Solution::atMostNGivenDigitSet(digits, n) << std::endl;
    //std::cout << Solution::digits2hexstring(digits,  n) << std::endl;




    return 0;
}
