class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        ios_base::sync_with_stdio(0);
        int n = matrix.size(),m = matrix[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 1; j<m; j++){
                matrix[i][j]+=matrix[i][j-1];
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = i; j<m; j++){
                unordered_map<int,int>mp;
                mp[0]++; int sum = 0;
                for(int k = 0; k<n; k++){
                    sum+=(matrix[k][j]-(i>0 ? matrix[k][i-1] : 0));
                    if(mp.find(sum-target)!=mp.end()){
                        ans+=mp[sum-target];
                    }
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};
