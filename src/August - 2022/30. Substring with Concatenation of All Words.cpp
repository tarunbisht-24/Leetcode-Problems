class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> mp, mp1;
        for(int i=0;i<words.size();i++) {
            mp[words[i]]++;
        }
        vector<int> ans;
        int length;
        for(length=0;s[length];length++);          
        int n = words[0].length();
        int m = words.size();
        for(int i=0;i<length-(m*n)+1;i++) {
            int size = words.size();
            int k = i;
            int flag=0;
            mp1 = mp;
            while(size--) {
                string str="";
                int j=k;
                while(k<j+n && k<length) {
                    str+=s[k++];
                }
                if(mp1.find(str)==mp1.end() || mp1[str]==0) {
                    flag = 1;
                    break;
                }
                else{
                   mp1[str]--; 
                }
            }
            if(flag==0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
