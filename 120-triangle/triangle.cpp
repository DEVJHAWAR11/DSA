// class Solution {
// public:
//     int solve(int i,int j,int n, vector<vector<int>>&triangle,vector<vector<int>>&dp){
//         if(i==n-1) return triangle[n-1][j];
//         if(dp[i][j]!=-1) return dp[i][j];
//         return dp[i][j] = triangle[i][j]+min(solve(i+1,j,n,triangle,dp),solve(i+1,j+1,n,triangle,dp));
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n=triangle.size();
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return solve(0,0,n,triangle,dp);
//     }
// };

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(i==n-1) dp[n-1][j]=triangle[n-1][j];
                else {
                    dp[i][j] = triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};