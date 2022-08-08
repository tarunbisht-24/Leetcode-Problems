class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector <int> longest(nums.size(),1);
        int MAX=1;
        for(int i=1;i<nums.size();i++)
        {
            for(int j =0;j<i;j++)
            {
                if(nums[j]<nums[i] && longest[j]>=longest[i]) 
                {
                    longest[i]=longest[j]+1;
                    MAX=max(MAX,longest[i]);
                }
            }   
        }
        return MAX;
    }
};
