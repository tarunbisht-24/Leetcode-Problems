class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count[256+1] = {0};  
        
        int ans = 0;
        int l = 0, r = 0; 
        
        while(r<s.length())
        {
            ++count[s[r]];
            
            while(count[s[r]] > 1) 
            {
                --count[s[l]];  
                ++l;  
            }
            
            ans = max(ans, r-l+1);
            ++r;  
        }
        
        return ans;
    }
};
