class Solution {
public:
    TreeNode* ans;
    
    void solve(TreeNode* original, TreeNode* cloned, TreeNode* target){
        if(original==NULL)
            return;
        if(original==target){
            ans = cloned; return;
        }
        solve(original->left,cloned->left,target);
        solve(original->right,cloned->right,target);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        solve(original,cloned,target);
        return ans;
    }
};
