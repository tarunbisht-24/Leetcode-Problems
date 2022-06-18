class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        int l=0,r=0;
        int sum = 0;  //current sum
        int maxSum = 0;  // max sum
        int n = nums.size();
        while(r<n) {
            m[nums[r]]++;
            sum += nums[r];
            if (m[nums[r]]>1) {
                while(m[nums[r]]>1) {
                    if (m[nums[l]]>0)
                        m[nums[l]]--;
                    sum-=nums[l];
                    l++;
                } 
            }
            maxSum = max(sum,maxSum);
            r++;
        }
        return maxSum;
     }
};
