#include <iostream>
#include <list>

using namespace std;
struct ListNode {
    int m_nKey;
    ListNode *m_pNext;
};

int main() {
    int num;
    ListNode header{0, nullptr}, *p, *pk;
    int theDesiredOne;
    cin >> num;
    p = &header;
    cin >> header.m_nKey;
    for (int i = 1; i < num; ++i) {
        int key;
        cin >> key;
        p->m_pNext = new ListNode{key, nullptr};
        p = p->m_pNext;
    }
    cin >> theDesiredOne;
    p = &header;
    for (int j = 0; j < theDesiredOne; ++j) {
        p = p->m_pNext;
    }
    pk = &header;
    while (p->m_pNext!= nullptr){
        p = p->m_pNext;
        pk = pk->m_pNext;
    }
    cout<<pk->m_nKey<<endl;


    return 0;
}
