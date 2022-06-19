class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        long long int sum =0;
        int n = nums.size();
        long long int ans = INT_MAX;
        for(int i=0;i<n;i++) sum+=nums[i];
        sum = sum-x;
        if(sum<0) return -1;
        
        long long int s =0;
        int i=0,j=0;
        while(j<n){
            s+=nums[j];
            while(s>sum){
                s-=nums[i];
                i++;
            }
            if(s==sum){
                ans = min(ans,(long long)(n-(j-i+1)));
                
            }
            j++;
        }
        
        return ans==INT_MAX ? -1 : ans;
        
    }
};
