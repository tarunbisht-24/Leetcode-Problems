class Solution {
public:
    
    bool isPossible(vector<int>& target) {
    long long int sum=0; int maxi=0;
    
    for(int i=0; i<target.size();i++){
        sum+=target[i];
        if(target[maxi]<target[i]){
            maxi=i;
        }
    }
    
    long long int d=sum-target[maxi];
    if(target[maxi]==1 || d==1) return true;
    if(d>target[maxi] || d==0 || target[maxi]%d==0) return false;
    
    target[maxi]%=d;
    
    return isPossible(target);
}
};
