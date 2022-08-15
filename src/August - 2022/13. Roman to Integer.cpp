class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        
        unordered_map<char,int> roman;
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;
        if(n == 1){
          return roman[s[0]];  
        }

        ans = roman[s[0]];
        for(int i=1;i<n;i++){
            
            if(roman[s[i-1]] < roman[s[i]]){
                ans = ans + (roman[s[i]] - 2 * roman[s[i-1]]);
            }
            else{
                ans = ans + roman[s[i]];
            }
        }
        
        return ans;
    }
    
};
