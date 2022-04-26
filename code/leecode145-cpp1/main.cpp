#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void preorder(TreeNode *root, vector<int> &vec){
        if(root== nullptr){
            return;
        } else{
            vec.emplace_back(root->val);
            preorder(root->left,vec);
            preorder(root->right,vec);
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        preorder(root,vec);
        return vec;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
