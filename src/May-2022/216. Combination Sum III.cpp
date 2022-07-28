class Solution {
public:
  vector<vector<int>>res;
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<int>ans;
      solve(k,n,ans,1,0,0);
      return res;
        
    }
    
void solve(int k,int n,vector<int>&ans,int idx,int sum,int x)
{
  if(sum==n && x==k)
  {
    res.push_back(ans); return;
  }
  else if(x>k|| sum>n) return;
  
  for(int i=idx;i<=9;i++)
  {
    sum+=i;
    ans.push_back(i);
    solve(k,n,ans,i+1,sum,x+1);
    sum-=i;
    ans.pop_back();
  }
}
};
