class Solution {
public:
    bool matches(string word,  string pattern){
    vector<char> pat(26,0),wr(26,0);
    if(word.size() != pattern.size()) return false;
    for(int i=0; i<word.size(); i++){
        char pat_ch = pattern[i];
        char wor_ch = word[i];
        if(pat[pat_ch - 'a'] == 0) pat[pat_ch - 'a'] = wor_ch;
        if(wr[wor_ch - 'a'] == 0) wr[wor_ch - 'a'] = pat_ch;
        if(pat[pat_ch-'a']!=wor_ch or wr[wor_ch-'a']!=pat_ch) return false;
    }
    return true;
}
vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    vector<string> res;
    for(auto it: words){
        if(matches(it, pattern)) res.push_back(it);
    }
    return res;
}
};
