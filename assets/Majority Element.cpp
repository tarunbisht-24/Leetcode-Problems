class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int ansIndex = 0;
        int count = 1;
        int result;
        int ans = 0;
        
        for(int i=1;i<n;i++)
        {
            if(nums[i]==nums[ansIndex])
                count++;
            else
                count--;
            
            if(count==0)
            {
                ansIndex = i;
                count = 1;
            }
        }
        
        result = nums[ansIndex];
        
        for(int i=0;i<n;i++)
        {
            if(result == nums[i])
                ans++;
        }
        
        return result;
    }
};
