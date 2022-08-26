class Solution {
public:
    bool reorderedPowerOf2(int n) {
       vector<int> v;
        while(n!=0)
        {
            v.push_back(n%10);
            n/=10;
        }
        
        sort(v.begin(),v.end()); 
        
        do{
            int temp=0,flag=0;
            for(int i=0;i<v.size();i++)
                {
                          if(i==0 && v[i]==0)
                            flag=1;
                            temp=temp*10+v[i];
            }
            if(flag==0&&__builtin_popcount(temp)==1) 
                return true;
        }
        
        while(next_permutation(v.begin(),v.end()));
        
        return false;
        
    }
};
