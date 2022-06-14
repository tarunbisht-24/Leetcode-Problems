class Solution {
public:
    int lcs(string a, int n , string b, int m){
        int t[n+1][m+1];
        
        for(int i =0; i<n+1; i++){
            t[i][0]= 0;
        }
        for(int j =0; j<m+1;j++){
            t[0][j]= 0;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j =1; j<m+1; j++){
                if(a[i-1]==b[j-1]){
                    t[i][j]= 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n][m]; 
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int s= lcs(word1,n, word2, m);
        return n+m-2*s;
    }
};
