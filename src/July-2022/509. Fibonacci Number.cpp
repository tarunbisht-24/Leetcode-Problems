class Solution {
public:
    int t[31] = {0}; 
    int fib(int n) {
        if(n == 0 ||  n == 1) 
            return n; 
        
        if(t[n] != 0) 
            return t[n];
        
        
        return t[n] = fib(n - 1) + fib(n - 2);
    }
};
