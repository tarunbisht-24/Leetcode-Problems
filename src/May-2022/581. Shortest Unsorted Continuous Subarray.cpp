class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        int n = nums.size();        
        int i = 0;
        int j = n - 1;
        
        while(i + 1 < n && nums[i] <= nums[i + 1])
            i++;
        
        while(j > 0 && nums[j] >= nums[j - 1])
            j--;
        
        if(i >= n - 1)
            return 0;
        
        int maxi = INT_MIN;
        int mini = INT_MAX;
        
        for(int k = i; k <= j; k++)
        {
            maxi = max(maxi, nums[k]);
            
            mini = min(mini, nums[k]);
        }
      
        int start = 0;  
        int end = n - 1;
        
        while(start <= i && nums[start] <= mini)
            start++;       
        
        while(end >= j && nums[end] >= maxi)
            end--;
        
        return end - start + 1;
    }
};
