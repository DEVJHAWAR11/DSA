// class Solution {
// public:
//     int solve(int idx,vector<int>&prices,int n,int buy,vector<vector<int>>&dp){
//         if(idx==n) return 0;
//         if(dp[idx][buy]!=-1) return dp[idx][buy];
//         int profit=0;
//         if(buy){
//             profit=max(-prices[idx]+solve(idx+1,prices,n,0,dp),0 + solve(idx+1,prices,n,1,dp));
//         }
//         else{
//             profit=max(prices[idx] +solve(idx+1,prices,n,1,dp),0 + solve(idx+1,prices,n,0,dp));
//         }
//         return dp[idx][buy] = profit;
//     }

//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>>dp(n,vector<int>(2,-1)); //arr[idx][buy]

//         return solve(0,prices,n,1,dp);  //initially can buy;
//     }
//};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         int profit=0;
//         vector<vector<int>>dp(n+1,vector<int>(2,0)); 
//         for(int i=n;i>=0;i++){
//             for(int buy=0;buy<=1;buy++){
//                 if(i==n) dp[i][buy]=0;
//                 else{
//                     if(buy){
//                         profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
//                     }
//                     else{
//                         profit=max(prices[i]+dp[i+1][1],dp[i+1][0]);
//                     }  
//                 }
//                 dp[i][buy]=profit;
//             }
//         }
//         return dp[0][1];     //was starting with buy=1 in memo
//     }
// };


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0)); 

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy) {
                    dp[i][buy] = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    dp[i][buy] = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
            }
        }

        return dp[0][1]; // start from index 0 with permission to buy
    }
};
