class Solution {
public:
    int camera=0;
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==-1)
            camera++;
        
        return camera;
    }
    
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int left=dfs(root->left);
        int right=dfs(root->right);
        
        if(left==-1||right==-1)
        {
            camera++;
            return 1;
        }
        else if(left==1||right==1)
            return 0;
        else
            return -1;
    }
};
