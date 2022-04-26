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

class BSTIterator {
private:
    vector<int> vec;
    vector<int>::iterator iter;
public:

    void inorder(TreeNode* root, vector<int> &vec){
        if(root== nullptr){
            return;
        } else{
            inorder(root->left,vec);
            vec.emplace_back(root->val);
            inorder(root->right,vec);
        }
    }

    BSTIterator(TreeNode* root) {
        inorder(root,vec);
        iter=vec.begin();
    }

    int next() {
        int tmp=*iter;
        iter++;
        return tmp;
    }

    bool hasNext() {
        if(iter==vec.end()){
            return false;
        } else{
            return true;
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
