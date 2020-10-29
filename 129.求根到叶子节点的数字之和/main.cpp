#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int sum = 0;
public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
            return 0;
        sumNode(root, 0);
        return sum;
    }

    void sumNode(TreeNode* node, int num){
        int tempNum = num*10 + node->val;
        if(node->left == nullptr && node->right == nullptr){
            sum += tempNum;
            return;
        }
        if(node->left)
            sumNode(node->left, tempNum);
        if(node->right)
            sumNode(node->right, tempNum);
    }
};


int main(){
    
}