// class Solution {
// public:
//     int solve(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&dp){
//         if(row==0 && col==0 && grid[row][col]!=1) return 1;
//         if(row <0 || col <0 || grid[row][col]==1) return 0;
//         if(dp[row][col]!=-1) return dp[row][col];
//         return dp[row][col] = solve(grid,row-1,col,dp) + solve(grid,row,col-1,dp);
//     }

//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int row=obstacleGrid.size();
//         int col=obstacleGrid[0].size();
//         vector<vector<int>>dp(row,vector<int>(col,-1));
//         return solve(obstacleGrid,row-1,col-1,dp);
//     }
// };

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0 && j==0 && obstacleGrid[i][j]!=1) 
                    dp[i][j]=1;
                else{
                    int up=0,left=0;
                    if(i>0 && obstacleGrid[i][j]!=1) up=dp[i-1][j];
                    if(j>0 && obstacleGrid[i][j]!=1) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[row-1][col-1];
    }
};