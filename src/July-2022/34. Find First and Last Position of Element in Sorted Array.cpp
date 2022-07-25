class Solution {
private:
    
    int firstOcc(vector<int> nums,int s, int e, int k)
    {
        int mid = s + (e-s)/2;
        int ans = -1;
        
        while(s<=e)
        {
            if(nums[mid]==k)
            {
                ans = mid;
                e = mid-1;
            }
            else if(nums[mid]<k)
                s = mid+1;
            else
                e = mid - 1;
            
            mid = s + (e-s)/2;
        }
        return ans;
    }
    
    int lastOcc(vector<int> nums,int s, int e, int k)
    {
        int mid = s + (e-s)/2;
        int ans = -1;
        
        while(s<=e)
        {
            if(nums[mid]==k)
            {
                ans = mid;
                s = mid+1;
            }
            else if(nums[mid]<k)
                s = mid+1;
            else
                e = mid - 1;
            
            mid = s + (e-s)/2;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int first = firstOcc(nums,0,nums.size()-1,target);
        int second = lastOcc(nums,0,nums.size()-1,target);
        return {first,second};
    }
};
