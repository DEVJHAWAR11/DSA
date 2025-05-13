// class Solution {
// public:
//     int usingRec(int n ,int index){
//         if(index==0) return 1;
//         if(index==1) return 1;

//         return usingRec(n,index-1) + usingRec(n,index-2);
//     }

//     int climbStairs(int n) {
//         int index=n;
//         int ans=usingRec(n,index);
//         return ans;
//     }
// };

class Solution {
public:
    int usingMemo(int n ,vector<int>&dp){
        if(n==0 || n==1) return 1;

        if(dp[n]!=-1) return dp[n];
        dp[n]=usingMemo(n-1,dp) + usingMemo(n-2,dp);
        return dp[n];
    }

    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return usingMemo(n,dp);
    }
};
