// class Solution {
// public:

//     void dfs(vector<vector<char>>&grid,int i,int j,vector<vector<int>>&vis){
//         vis[i][j]=1;
//         //for all 6 directions
//         for(int delrow=-1;delrow<=1;delrow++){
//             for(int delcol=-1;delcol<=1;delcol++){
//                 int ni=delrow+i;
//                 int nj=delcol+j;

//                 if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]=='1'&&vis[ni][nj]==0)
//                     dfs(grid,ni,nj,vis);
//             }
//         }

//     }

//     int numIslands(vector<vector<char>>& grid) {
//         int m= grid.size(),n=grid[0].size();
//         vector<vector<int>>vis(m,vector<int>(n,0));
//         int cnt=0;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(vis[i][j]==0 && grid[i][j]=='1'){
//                     dfs(grid,i,j,vis);
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:

    void dfs(vector<vector<char>>&grid,int i,int j,vector<vector<int>>&vis){
        vis[i][j]=1;
        //for  4 directions
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};

        for(int k=0;k<4;k++){
            int ni=dr[k]+i;
            int nj=dc[k]+j;

            if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]=='1'&&vis[ni][nj]==0)
                    dfs(grid,ni,nj,vis);
        }

    }

    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(grid,i,j,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};