class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> um[26];
        int n = s.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            um[s[i]-'a'].push_back(i);
        }
        for(string &x : words)
        {
            int idx = -1;
            for(int i = 0; i < x.size(); i++)
            {
                auto y = upper_bound(um[x[i]-'a'].begin(), um[x[i]-'a'].end(), idx);
                if(y == um[x[i]-'a'].end()) break;
                if(i == x.size()-1) 
                    ans++;
                idx = *y;
            }
        }
        return ans;
    }
};
