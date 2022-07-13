class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)  return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> row;
        while(!q.empty()) {
            TreeNode *t = q.front();
            q.pop();
            if (t) row.push_back(t->val);

            if (t and t->left)    q.push(t->left);
            if (t and t->right)    q.push(t->right);

            if (!q.front()) {
                ans.push_back(row);
                row.clear();
                q.pop();
                q.push(NULL);  
            }
        }

        return ans;
    }
};
