class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& arr, int K) {
        const int n = (int)arr.size();
        const int m = (int)arr[0].size();
        
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                arr[j][i] += arr[j-1][i];
            }
        }
        
        long long ans = -1e9;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                set<long long> pos;
                long long curr = 0LL;
                for (int k = 0; k < m; ++k) {
                    if (i == 0) {
                        curr += arr[j][k];    
                    } else {
                        curr += arr[j][k] - arr[i-1][k];
                    }
                    
                    if (curr <= K) {
                        ans = max(ans, curr);
                    }
                    int x = curr - K;
                    
                    auto it = pos.lower_bound(x);
                    if (it != pos.end() && *it < x) {
                        ++it;
                    }
                    
                    if (it != pos.end() && curr - *it <= K) {
                        ans = max(ans, curr - *it);
                    }
                    pos.insert(curr);
                }
            }
        }
        
        return ans;
    }
};
