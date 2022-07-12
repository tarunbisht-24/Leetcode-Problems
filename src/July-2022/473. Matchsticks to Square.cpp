class Solution {
public:
    bool solve(vector<int> &match, vector<int>&sq, int ind){
        
        if(ind==match.size()){
            return sq[0]==sq[1] && sq[1]==sq[2] && sq[2]==sq[3] && sq[0]==0;
        }
        
        set<int> st;
        for(int i=0; i<4; i++){
            if(sq[i]-match[ind]>=0 && st.find(sq[i])==st.end()){
                sq[i]-=match[ind];
                if(solve(match, sq, ind+1)) return true;
                sq[i]+=match[ind];
                
                st.insert(sq[i]);
            }
        }
        
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        int sum= accumulate(matchsticks.begin(), matchsticks.end(),0);
        
        if(sum%4) return false;
        
        vector<int> sq(4, sum/4);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        return solve(matchsticks, sq, 0);
    }
};
