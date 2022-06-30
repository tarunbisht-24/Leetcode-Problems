class Solution {
private:
    
    void solve(vector<int> nums, int index, set<vector<int>> &st)
    {
        if(index == nums.size())
        {
            st.insert(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);
            solve(nums,index+1,st);
            swap(nums[i],nums[index]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        set<vector<int>> st;
        solve(nums,0,st);
        vector<vector<int>> ans;
        
        for(auto x:st)
            ans.push_back(x);
        
        return ans;
    }
};
