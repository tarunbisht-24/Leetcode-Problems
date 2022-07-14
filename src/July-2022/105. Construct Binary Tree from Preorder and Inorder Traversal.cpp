class Solution {
public:
      unordered_map<int,int>mp;
     int index =0;
     TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int low,int high){
         if(low>high) return NULL;
         TreeNode* res = new TreeNode(preorder[index++]);
         if(low==high) return res;
         int mid = mp[res->val];
         res->left = solve(preorder,inorder,low,mid-1);
         res->right = solve(preorder,inorder,mid+1,high);
         return res;
     }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index =0;
        int n = inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]= i;
        }
        
        TreeNode *root = solve(preorder,inorder,0,n-1);
        return root;
    }
};
