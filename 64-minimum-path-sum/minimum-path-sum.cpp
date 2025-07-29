// class Solution {
// public:
//     int solve(vector<vector<int>>&grid,int m,int n,vector<vector<int>>&dp){
//         if(m==0 && n==0) return grid[0][0];
//         if(m<0 || n<0) return INT_MAX;   //to say that it is invalid path ..with 0 it considers it valid path
//         if(dp[m][n]!=-1) return dp[m][n];
//         return dp[m][n] = grid[m][n]+min(solve(grid,m-1,n,dp),solve(grid,m,n-1,dp));
//     }

//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return solve(grid,m-1,n-1,dp);
//     }
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[0][0];
                else{
                    int up = (i > 0) ? dp[i - 1][j] : INT_MAX;
                    int left = (j > 0) ? dp[i][j - 1] : INT_MAX;
                    dp[i][j]=grid[i][j]+min(up,left);
                }
            }
        }

        return dp[m-1][n-1];
    }
};