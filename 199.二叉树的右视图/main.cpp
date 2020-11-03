class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;
        queue<TreeNode*> q;
        int count = 0;
        q.push(root);
        while(!q.empty()){
            count = q.size();
            result.emplace_back(q.front()->val);
            while(count--){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->right)
                    q.push(temp->right);
                if(temp->left)
                    q.push(temp->left);
            }
        }
        return result;
    }
};