class Solution {
public:
    bool checkBST(TreeNode* root, long from, long to)
    {
        if(!root) return true;
        if(root->val <= from || root->val >= to)
            return false;
        return checkBST(root->left, from, root->val) && checkBST(root->right, root->val, to);
    }
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX);
    }
};
