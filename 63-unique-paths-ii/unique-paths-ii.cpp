class Solution {
public:
    int solve(vector<vector<int>>&grid,int row,int col,vector<vector<int>>&dp){
        if(row==0 && col==0 && grid[row][col]!=1) return 1;
        if(row <0 || col <0 || grid[row][col]==1) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col] = solve(grid,row-1,col,dp) + solve(grid,row,col-1,dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        vector<vector<int>>dp(row,vector<int>(col,-1));
        return solve(obstacleGrid,row-1,col-1,dp);
    }
};