class Solution {
public:
    int mirrorReflection(int p, int q)
    {
        int lcm=least_common_multiple(p,q);
        
        int m=lcm/p;
        int n=lcm/q;
        
        if(m%2==0) return 0;       
        if(m%2==1 && n%2==1) return 1; 
        if(m%2==1 && n%2==0) return 2; 

        return -1;
    }
    
    int least_common_multiple(int p, int q)
    {
        int gcd=greatest_common_divisor(p,q);
        return p*q/gcd;
    }
    
    int greatest_common_divisor(int p, int q)
    {
        
        while(q!=0)
        {
            int tmp=p;
            p=q;
            q=tmp%q;
        }
        
        return p;
    }
};
