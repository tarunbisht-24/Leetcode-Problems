class Solution {
private:
    vector<int> res;
    void levelorderHelper(TreeNode *root){
        if(!root) return;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int count = q.size();
            while(count-- > 0){
                TreeNode *curr = q.front();
                q.pop();
                if(count == 0){
                    res.push_back(curr->val);
                }
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        levelorderHelper(root);
        return res;
    }
};
