class Solution {
public:
int longestValidParentheses(string s) {
    
    int n = s.length();
    
    stack<int> st;
    for(int i = 0; i < n; i++){
        
        char c = s[i];
        
        if(c == '(')
            st.push(i);
        else{
            if(st.size() && s[st.top()] == '(')
                st.pop();
            else st.push(i);
        }
            
    }
    
    if(!st.size())  
        return n;
    
    int r = n , l, ans = 0;
    
    while(st.size()){
        l = st.top();
        st.pop();
        ans = max(ans , r-l-1);
        r = l;
    }
    
    ans = max(ans, r);
     
    return ans;
  }
};
