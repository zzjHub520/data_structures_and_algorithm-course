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

    void inorder(TreeNode *root, vector<int> &vec){
        if(root== nullptr){
            return;
        } else{
            inorder(root->left,vec);
            vec.emplace_back(root->val);
            inorder(root->right,vec);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorder(root,vec);
        return vec;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
