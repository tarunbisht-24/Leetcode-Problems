class Solution {
public:
     int dx[4] = {0,1,0,-1};
     int dy[4] = {1,0,-1,0};

    void dfs(int i,int j,int z,vector<vector<int>>& heights,vector<vector<vector<int>>>&reach){
        reach[i][j][z]=1;
        for(int k=0;k<4;k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni>=0 && ni<heights.size() && nj>=0 && nj<heights[0].size() && reach[ni][nj][z]==0 && heights[i][j]<=heights[ni][nj])
             {
                 dfs(ni,nj,z,heights,reach);
             }
        }
    }      
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<vector<int>>>reach(n,vector<vector<int>>(m,vector<int>(2,0)));
         vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
             // from Pacific Ocean
            dfs(i,0,0,heights,reach);
             // from Atlantic Ocean
            dfs(i,m-1,1,heights,reach);
        }
      
        for(int j=0;j<m;j++)
        {
            // From Pacific Ocean
            dfs(0,j,0,heights,reach);
            //From Atlantic Ocean
           dfs(n-1,j,1,heights,reach);
        }
        
        //result
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(reach[i][j][0]==1 && reach[i][j][1]==1 )
                 ans.push_back({i,j});
            }
        }
        return ans;
    }
};
