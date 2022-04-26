#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    static void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        } else if(m==0){
            for(int i=0; i<n;++i){
                nums1[i]=nums2[i];
            }
            return;
        }

        int len=m+n;
        vector<int> tmp(len,0);
        nums1[m]=INT_MAX;
        nums2.emplace_back(INT_MAX);
        int x=0,y=0;
        for(int i=0; i<len;++i){
            if(nums1[x]<nums2[y]){
                tmp[i]=nums1[x];
                ++x;
            } else{
                tmp[i]=nums2[y];
                ++y;
            }
        }
        for(int i=0;i<len;++i){
            nums1[i]=tmp[i];
        }
    }
};


int main() {
    vector<int> nums1{1};
    vector<int> nums2;
    Solution::merge(nums1, 1, nums2, 0);
    for(auto ele:nums1){
        cout<<ele<<endl;
    }

    return 0;
}
