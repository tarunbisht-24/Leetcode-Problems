class Solution {
public:
    int K;
    long long DFS(vector<int>& arr, int idx, unordered_map<int,long long>& dp){
        
        if (idx == arr.size())
            return 0;
        
        long long count = 1; 
        
        for(int i = 0 ; i < idx ; i++){
            int a = arr[i];
            if(arr[idx] % a != 0)
                continue;
            int b = arr[idx]/a;
            if(dp.find(a) != dp.end() && dp.find(b) != dp.end()){
                count = (count + dp[b]*dp[a])%K;
            }
        }
        
        dp[arr[idx]] = count;
        return count;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        K = 1000000007;
        sort(arr.begin(), arr.end());
        unordered_map<int, long long> dp;
        long long c = 0;
        for(int i = 0 ; i < arr.size() ; i++)
            c = (c + DFS(arr, i, dp))%K;
        return c;
    }
};
