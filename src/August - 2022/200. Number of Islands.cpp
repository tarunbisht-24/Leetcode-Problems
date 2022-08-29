class Solution {
public:
vector<int> dx,dy;
void dfs(vector<vector<char> > &grid,int x,int y){
    grid[x][y]='0';

    for (int i = 0; i < 4; i++)
    {
        int cx=x+dx[i],cy=y+dy[i];
        if(cx>=0 && cx<grid.size() && cy>=0 && cy<grid[0].size() && grid[cx][cy]=='1'){
            dfs(grid,cx,cy);
        }
     
    }
    
}
int numIslands(vector<vector<char>>& grid) {
        dx={0,0,1,-1};
        dy={1,-1,0,0};
        int ans=0;
        for (int i = 0; i < grid.size(); i++)
        {
            /* code */
            for (int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    ans++;
                }

            }
            
        }
        return ans;
        
}
};
