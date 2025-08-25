class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[i][j]=1;

        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};

        for(int k=0;k<4;k++){
            int ni=dx[k]+i;
            int nj=dy[k]+j;

            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]==1 && vis[ni][nj]==0){
                dfs(ni,nj,grid,vis);
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0 || j==n-1 || i==m-1){
                    if(grid[i][j]==1 && !vis[i][j]){
                        dfs(i,j,grid,vis);
                    }
                }
            }
        }
        int cnt1=0,cnt2=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1){
                    cnt1++;
                }
                if(grid[i][j]==1){
                    cnt2++;
                }
            }
        }
        return cnt2-cnt1;
    }
};