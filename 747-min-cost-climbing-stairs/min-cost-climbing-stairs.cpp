// class Solution {
// public:
//     int solve(vector<int>&cost,int n,vector<int>&dp){
//         if(n==0) return 0;
//         if(n==1) return 0;   //think as if we are starting from this step ie consider as ground so no cost

//         if(dp[n]!=-1) return dp[n];

//         return dp[n]= min(cost[n-1]+solve(cost,n-1,dp),cost[n-2]+solve(cost,n-2,dp));

//     }

//     int minCostClimbingStairs(vector<int>& cost) {
//         vector<int>dp(cost.size()+1,-1);
//         return solve(cost,cost.size(),dp);
//     }
// };

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        dp[0]=0,dp[1]=0;
        for(int i=2;i<n+1;i++){
            dp[i]=min(cost[i-1]+dp[i-1],cost[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};