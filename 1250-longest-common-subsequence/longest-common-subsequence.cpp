// class Solution {
// public:
//     int LCS(string &text1,string &text2,int n,int m,vector<vector<int>>&dp){
//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<m+1;j++){
//                 if(text1[i-1]==text2[j-1])
//                     dp[i][j]=1+dp[i-1][j-1];
//                 else
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//        return dp[n][m];
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         int n=text1.size();
//         int m=text2.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//         return LCS(text1,text2,n,m,dp);
//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<int>curr(m+1,0),prev(m+1,0);
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(text1[i-1]==text2[j-1])
                    curr[j] = 1 + prev[j-1];
                else
                    curr[j] = max(curr[j-1],prev[j]);  
            }
            prev=curr;
        }
        return curr[m];
    }
};