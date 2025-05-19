// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int n=s.size(),m=t.size();
//         int dp[n+1][m+1];
//         memset(dp,0,sizeof(dp));
//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<m+1;j++){
//                 if(s[i=1]==t[j-1])
//                     dp[i][j]=1+dp[i-1][j-1];
//                 else
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//         return n==dp[n][m];
//     }
// };

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pntr = 0;
        for (int i=0; i<t.length(); i++) {
            if (t[i] == s[pntr]) {
                pntr++;
            }
        }
       
        return pntr==s.length();
    }
};