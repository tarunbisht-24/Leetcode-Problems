class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> mp1;
        for(int j=0; j<ransomNote.size(); j++){
            mp1[ransomNote[j]]++;
        }
        
        for(int i=0; i<magazine.size(); i++){
            if(mp1.find(magazine[i])!=mp1.end()){
                mp1[magazine[i]]--;
                
                if(mp1[magazine[i]]==0){
                    mp1.erase(magazine[i]);
                }
            }
        }
        if(mp1.empty()){
            return true;
        }else{
            return false;
        }
    }
};
