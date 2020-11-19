class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        if(root->left == nullptr){
            flatten(root->right);
            return;
        }
        auto left = root->left;
        auto lastLeft = left;
        while(lastLeft->right)
            lastLeft = lastLeft->right;
        lastLeft->right = root->right;
        root->right = left;
        root->left = nullptr;
        flatten(left);
    }
};