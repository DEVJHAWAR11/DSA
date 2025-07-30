class Solution {
public:
    int mini(int a,int b,int c){
        if(a<b){
            if(a<c)
                return a;
            else
                return c;
        }
        else if(b<c)
            return b;
        else
            return c;
    }

    int solve(int i,int j ,vector<vector<int>>&matrix,int n,vector<vector<int>>&dp){
        if(j>=n || j<0) return INT_MAX;
        if(i==n-1) return matrix[n-1][j];
        if(dp[i][j]!=-2) return dp[i][j];

        int down=solve(i+1,j,matrix,n,dp);
        int rdiag=solve(i+1,j+1,matrix,n,dp);
        int ldiag=solve(i+1,j-1,matrix,n,dp);


        return dp[i][j] = matrix[i][j] + mini(down,rdiag,ldiag);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size(),ans=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(n,-2));  //-2 as last test case ans is -1 and giving tle
        for(int j=0;j<n;j++){
            ans=min(solve(0,j,matrix,n,dp),ans);
        }
        return ans;
    }
};