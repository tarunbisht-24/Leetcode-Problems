class Solution {
public:
    TreeNode* divide(vector<int>&n,int l,int r){
        if(l<r){
            int m = l-(l-r)/2;
            TreeNode* node = new TreeNode(n[m]);
            node->left = divide(n,l,m);
            node->right = divide(n,m+1,r);
            
            return node;
        }
        return NULL;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* node = divide(nums,0,nums.size());
        return node;
    }
};
