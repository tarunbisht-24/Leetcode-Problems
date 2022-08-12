class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL)
            return NULL;
        
        if(root->val < P->val && root->val < Q->val)
            return lowestCommonAncestor(root->left, P, Q);
        
        else if(root->val > P->val && root->val > Q->val)
            return lowestCommonAncestor(root->right, P, Q);
        
        return root;
    }
};
