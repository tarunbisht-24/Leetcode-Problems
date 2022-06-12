class Solution {
public:
    int maxProduct(vector<string>& words) {
        int ans=0;
        for(int i=0;i<words.size();i++)
            sort(words[i].begin(),words[i].end());
        for(int i=0;i<words.size();i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                int k=0,l=0;
                while(k<words[i].size() and l<words[j].size() and words[i][k]!=words[j][l])
                {
                    if(words[i][k]<words[j][l])
                        k++;
                    else
                        l++;
                }
                if(k==words[i].size() or l==words[j].size())
                {
                    int x=words[i].size()*words[j].size();
                    ans=max(ans,x);
                }
            }
        }
        return ans;
    }
};
