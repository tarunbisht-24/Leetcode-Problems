class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;

        int i = 1, j = numbers.size();  
        while(i!=j)
        {
           if(numbers[i]+numbers[j]==target)
            {
                ans.push_back(min(i,j));
                ans.push_back(max(i,j));
                break;
            }
            else if(numbers[i]+numbers[j]>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
