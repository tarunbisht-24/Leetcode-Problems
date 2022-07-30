class Solution {
public:
    int time = 0;
    void dfs(vector<int> a[],vector<bool> &vis,vector<int> &parent,vector<int> &disc,vector<int> &low,vector<vector<int>> &res,int sv)
    {
        vis[sv] = 1;
        disc[sv] = time;
        low[sv] = time;
        time++;
        
        for(auto nbr:a[sv])
        {
            if(disc[nbr]==-1)
            {
                parent[nbr] = sv;
                dfs(a,vis,parent,disc,low,res,nbr);
                
                low[sv] = min(low[sv],low[nbr]);
                
                if(low[nbr]>disc[sv])
                    res.push_back({sv,nbr});
            }
            else if(nbr!=parent[sv])
            {
                low[sv] = min(low[sv],disc[nbr]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<int> a[n];
        for(auto it:con)
        {
            int x = it[0];
            int y = it[1];
            a[x].push_back(y);
            a[y].push_back(x);
        }
        
        
        time = 0;
        
        vector<bool> vis(n,false);
        vector<int> parent(n,-1);
        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        
        vector<vector<int>> res;
        
        for(int i = 0;i<n;i++)
        {
            if(disc[i]==-1)
            {
                dfs(a,vis,parent,disc,low,res,i);
            }
        }
        return res;
    }
};
