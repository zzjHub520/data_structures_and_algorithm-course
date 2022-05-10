#include <iostream>
#include <vector>
#include <regex>

using namespace std;

int score1_len(string &cipherstr) {
    int len = cipherstr.size();
    if (len <= 4) {
        return 5;
    } else if (5 <= len && len <= 7) {
        return 10;
    } else {
        return 25;
    }
}

int score2_letter(string &cipherstr) {
    regex reg(R"((?=[a-zA-Z]).)");
    vector<string> strvec(sregex_token_iterator(cipherstr.begin(), cipherstr.end(), reg, {0}), sregex_token_iterator());
    if (strvec.empty()) {
        return 0;
    } else {
        bool flag1 = false;
        bool flag2 = false;
        for (auto elestr:strvec) {
            if ('a' <= elestr[0] && elestr[0] <= 'z') {
                flag1 = true;
            } else {
                flag2 = true;
            }
            if (flag1 && flag2) {
                return 20;
            }
        }
        return 10;
    }
}

int score3_digital(string &cipherstr) {
    regex reg(R"((?=\d).)");
    vector<string> strvec(sregex_token_iterator(cipherstr.begin(), cipherstr.end(), reg, {0}), sregex_token_iterator());
    if (strvec.empty()) {
        return 0;
    } else {
        if (strvec.size() == 1) {
            return 10;
        } else {
            return 20;
        }
    }
}

bool is_symbol(char c) {
    if ('!' <= c && c <= '/') {
        return true;
    } else if (':' <= c && c <= '@') {
        return true;
    } else if ('[' <= c && c <= '`') {
        return true;
    } else if ('{' <= c && c <= '~') {
        return true;
    }
    return false;
}

int score4_symbol(string &cipherstr) {
    int count = 0;
    for (auto ele:cipherstr) {
        if (is_symbol(ele)) {
            count++;
        }
        if (count > 1) {
            return 25;
        }
    }
    if (count == 0) {
        return 0;
    } else {
        return 10;
    }
}

int score5_award(string &cipherstr) {
    int score4 = score4_symbol(cipherstr);
    int score3 = score3_digital(cipherstr);
    int score2 = score2_letter(cipherstr);

    if (score2 == 20 && score3 > 0 && score4 > 0) {
        return 5;
    } else if (score2 > 0 && score3 > 0 && score4 > 0) {
        return 3;
    } else if (score2 > 0 && score3 > 0) {
        return 2;
    }
    return 0;
}

int main() {

    string cipherstr = "38$@NoNoN";
    getline(cin, cipherstr);
    int score_total =
            score1_len(cipherstr) + score2_letter(cipherstr) +
            score3_digital(cipherstr) + score4_symbol(cipherstr) +
            score5_award(cipherstr);

    if (score_total >= 90) {
        cout << "VERY_SECURE" << endl;
    } else if (score_total >= 80) {
        cout << "SECURE" << endl;
    } else if (score_total >= 70) {
        cout << "VERY_STRONG" << endl;
    } else if (score_total >= 60) {
        cout << "STRONG" << endl;
    } else if (score_total >= 50) {
        cout << "AVERAGE" << endl;
    } else if (score_total >= 25) {
        cout << "WEAK" << endl;
    } else {
        cout << "VERY_WEAK" << endl;
    }

    return 0;
}
