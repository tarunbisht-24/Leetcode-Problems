class Solution {
public:
            int mod = 1e9+7;
int maxArea(int h, int w, vector<int>& hori, vector<int>& verti)     {
    
    sort(hori.begin(),hori.end());
    sort(verti.begin(),verti.end());
    
    hori.push_back(h);
    verti.push_back(w);
    
    int i,maxr=hori[0],maxc=verti[0],temp;
    
    for(i=1;i<hori.size();i++)
    {
        temp = hori[i] - hori[i-1];
        maxr = max(temp,maxr);
    }
    
    for(i=1;i<verti.size();i++)
    {
        temp = verti[i] - verti[i-1];
        maxc = max(temp,maxc);
    }
    
    
    return (int)((long)maxr*maxc%mod);
}
};
