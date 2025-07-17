// class Solution {
// public:
//     int tribonacci(int n) {
//         vector<int>dp(n+1,0);
//         if(n==1 || n==2) return 1;
//         if(n==0) return 0;
//         dp[1]=1,dp[2]=1;
//         for(int i=3;i<n+1;i++){
//             dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    int tribonacci(int n) {
        int prev3=0,prev2=1,prev1=1,curr=0;
        if(n==1||n==2) return 1;
        for(int i=3;i<n+1;i++){
            curr=prev1+prev2+prev3;
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};