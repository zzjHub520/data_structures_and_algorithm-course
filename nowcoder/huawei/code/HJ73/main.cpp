#include <iostream>

using namespace std;

int feddays(int yyyy) {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0)) {
        return 29;
    } else {
        return 28;
    }
}

int howmuchdays(int yyyy, int mm, int dd) {
    int last = 0;
    switch (1) {
        case 1:
            if (mm - 1 == 0)break;
            last += 31;
        case 2:
            if (mm - 1 == 1)break;
            last += feddays(yyyy);
        case 3:
            if (mm - 1 == 2)break;
            last += 31;
        case 4:
            if (mm - 1 == 3)break;
            last += 30;
        case 5:
            if (mm - 1 == 4)break;
            last += 31;
        case 6:
            if (mm - 1 == 5)break;
            last += 30;
        case 7:
            if (mm - 1 == 6)break;
            last += 31;
        case 8:
            if (mm - 1 == 7)break;
            last += 31;
        case 9:
            if (mm - 1 == 8)break;
            last += 30;
        case 10:
            if (mm - 1 == 9)break;
            last += 31;
        case 11:
            if (mm - 1 == 10)break;
            last += 30;
        case 12:
            if (mm - 1 == 0)break;
    }
    return last + dd;
}


int main() {

    int yyyy, mm, dd;
    cin >> yyyy >> mm >> dd;

    cout << howmuchdays(yyyy, mm, dd) << endl;


    return 0;
}
