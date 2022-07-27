class Solution {
public:
    string removeDuplicates(string a, int k) {
        stack<pair<char,int>> s;
        int cnt=0;
        for(int i=0;i<a.length();i++)
        { cnt=0;
            if(s.empty())
            {
               cnt++;
               s.push({a[i],cnt});
            }
            else if(s.top().first != a[i])
            {
                cnt++;
                 s.push({a[i],cnt});
            }
            else if(s.top().first==a[i])
            {
                s.top().second++;
                if(s.top().second==k)
                {
                    s.pop();
                }
            }
        }
        string ans;
        while(!s.empty())
        {
            for(int i=0;i<s.top().second;i++)
            {
                ans.push_back(s.top().first);
            }
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
