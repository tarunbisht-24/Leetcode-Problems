class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        vector<bool> pre(n, false), suff(n, false);
        pre[0] = suff[n-1] = true;
        for(int i = 1; i < n; i++) {
            if(nums[i] >= nums[i-1])
                pre[i] = pre[i-1];
            else
                pre[i] = false;
        }
        for(int i = n-2; i >= 0; i--) {
            if(nums[i] <= nums[i+1]) 
                suff[i] = suff[i+1];
            else 
                suff[i] = false;
        }
        for(int i = 0; i < n; i++) {
            bool l = true, r = true;
            int val1 = INT_MIN, val2 = INT_MAX;
            if(i-1 >= 0) {
                l = pre[i-1];
                val1 = nums[i-1];
            }
            if(i+1 < n) {
                r = suff[i+1];
                val2 = nums[i+1];
            }
            if(l&&r&&val1 <= val2) return true;
        }
        return false;
    }
};
