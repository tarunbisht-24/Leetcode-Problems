class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(27, 0);
        int freq = 0, del_cnt = 0;
        for(int i = 0; i < s.length(); i++)
            v[s[i] - 'a']++;
        sort(v.begin(), v.end(), greater<int>());
        freq = v[0] - 1 <= 0 ? 0 : v[0] - 1;
        for(int i = 1; i < v.size(); i++){
            if(v[i] > freq){
                del_cnt += v[i] - freq;
                v[i] = freq;
            }
            freq = v[i] - 1 <= 0 ? 0 : v[i] - 1;
        }
        return del_cnt;
    }
};
