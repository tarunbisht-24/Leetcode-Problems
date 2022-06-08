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
		// return true if size is 1
        if(n==1)
            return 1;
		// else check if the given string is palindrome
        bool flag = isPalindrome(s);
        
		// if palindrome then we can remove it in 1 step
		if(flag)
            return 1;
			
		// else the main logic part is here , the question says  palindromic "subsequences"
		// then we can remove all a's in 1st step and all b's in 2nd step hence ans is 2
        return 2;
    }
};
