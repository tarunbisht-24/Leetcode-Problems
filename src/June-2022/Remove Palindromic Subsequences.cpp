class Solution {
public:
    bool isPalindrome(string s)
    {
        for(int i=0;i<(int)(s.size()/2);i++)
        {
            if(s[i]!=s[(int)s.size() - i - 1])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        int n = s.size();
        if(n==1)
            return 1;
        bool flag = isPalindrome(s);
        
		if(flag)
            return 1;
      
        return 2;
    }
};
