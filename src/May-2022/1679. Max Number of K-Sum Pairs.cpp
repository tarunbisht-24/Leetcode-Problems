class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0,start=0,end=nums.size()-1;
        while(start<end){
            if(nums[start]+nums[end]==k){
                start++;
                end--;
                ans++;
            } else if(nums[start]+nums[end]>k){
                end--;
            } else {
                start++;
            }
        }
        return ans;
    }
};
