class Solution {
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    int recursion(vector<vector<int>>& nums)
    {
        vector<int> ans;
        int n = nums.size();
        ans.push_back(nums[0][1]);
        for(int i = 1; i < n; i++)
        {
            int sz = ans.size();
            if(nums[i][1] > ans[sz-1])
            {
                ans.push_back(nums[i][1]);
                continue;
            }
            int left = 0, right = sz-1, nsrt = sz-1;
            while(left < right)
            {
                int mid = left + (right-left)/2;
                if(ans[mid] >= nums[i][1])
                {
                    right = mid;
                    nsrt = mid;
                }
                else if(ans[mid] < nums[i][1])
                {
                    left = mid+1;
                }
            }
            ans[nsrt] = nums[i][1];
        }
        return ans.size();
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), comp);
        return recursion(envelopes);
    }
};
