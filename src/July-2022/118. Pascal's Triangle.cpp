class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        vector<int> ele;
        ele.push_back(1);
        ans.push_back(ele);
        for(int i=1;i<n;i++){
            vector<int> ele(i+1);
            for(int j=0;j<=i;j++){
                if(j==0){
                    ele[j]=1;
                }else if(j==i){
                    ele[j]=1;
                }else{
                    ele[j]=ans[i-1][j-1]+ans[i-1][j];
                }
            }
            ans.push_back(ele);
        }
        return ans;
    }
};
