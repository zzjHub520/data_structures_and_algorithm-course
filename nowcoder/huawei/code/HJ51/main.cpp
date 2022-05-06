#include <iostream>
#include <list>
#include <vector>

using namespace std;
struct ListNode {
    int m_nKey;
    ListNode *m_pNext;
};

int main() {
    int num;
    vector<int> result;
    while (cin >> num) {
        ListNode header{0, nullptr}, *p, *pk;
        int theDesiredOne;
        p = &header;
        cin >> header.m_nKey;

        for (int i = 1; i < num; ++i) {
            int key;
            cin >> key;
            p->m_pNext = new ListNode{key, nullptr};
            p = p->m_pNext;
        }
        cin >> theDesiredOne;
        if (theDesiredOne < num) {
            p = &header;
            for (int j = 1; j < theDesiredOne; ++j) {
                p = p->m_pNext;
            }
            pk = &header;
            while (p->m_pNext != nullptr) {
                p = p->m_pNext;
                pk = pk->m_pNext;
            }
            result.emplace_back(pk->m_nKey);
        } else if (theDesiredOne == num) {
            result.emplace_back(header.m_nKey);
        }
    }
    for (auto ele:result) {
        cout << ele << endl;
    }
    return 0;
}
