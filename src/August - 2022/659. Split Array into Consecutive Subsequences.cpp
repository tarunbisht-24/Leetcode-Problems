class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int>count,need;
        for(auto it:nums){
            count[it]++;
        }
        
        for(auto it:nums){
            if(count[it]==0) continue;
           else if(need[it]>0){
               need[it]--;
               count[it]--;
               need[it+1]++;
           } else if(count[it+1] && count[it+2]){
               count[it]--;
               count[it+1]--;
               count[it+2]--;
               need[it+3]++;
           }else{
               return false;
           }
        }
        return true;
        
        
    }
};
