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

// class Solution {
// public:
//     int usingMemo(int n ,vector<int>&dp){
//         if(n==0 || n==1) return 1;

//         if(dp[n]!=-1) return dp[n];
//         dp[n]=usingMemo(n-1,dp) + usingMemo(n-2,dp);
//         return dp[n];
//     }

//     int climbStairs(int n) {
//         vector<int>dp(n+1,-1);
//         return usingMemo(n,dp);
//     }
// };

// class Solution {
// public:
//     int usingTabu(int n,vector<int>&dp){
//         dp[0]=1;
//         dp[1]=1;
//         if(n==0 || n==1) return dp[0];
//         for(int i=2;i<=n;i++){
//             dp[i]=dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }

//     int climbStairs(int n) {
//        vector<int>dp(n+1,-1);
//        return usingTabu(n,dp); 
//     }
// };

class Solution {
public:
    int climbStairs(int n) {
       int prev=1,curr=1;
       for(int i=2;i<=n;i++){
            int temp=prev+curr;
            prev=curr;
            curr=temp;
       }
       return curr;
    }
};