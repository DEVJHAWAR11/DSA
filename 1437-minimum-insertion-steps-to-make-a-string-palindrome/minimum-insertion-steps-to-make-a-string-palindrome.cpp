class Solution {
public:
    int minInsertions(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        int n =s.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                if(s[i-1]==r[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return n-dp[n][n];
    }
};