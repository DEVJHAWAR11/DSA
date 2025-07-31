class Solution {
public:
    // int solve(int idx,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
    //     if(idx==prices.size() || cap==0) return 0;
    //     if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
    //     int profit=0;
    //     if(buy){
    //         profit=max(-prices[idx] + solve(idx+1,0,cap,prices,dp),solve(idx+1,1,cap,prices,dp));
    //     }
    //     else{
    //         profit=max(prices[idx] + solve(idx+1,1,cap-1,prices,dp),solve(idx+1,0,cap,prices,dp));
    //     }
    //     return dp[idx][buy][cap] = profit;
    // }

    // int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
    //     for(int i=n-1;i>=0;i--){
    //         for(int buy=0;buy<=1;buy++){
    //             for(int cap=1;cap<=2;cap++){
    //                 if(buy)
    //                     dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap],dp[i+1][1][cap]);
    //                 else
    //                     dp[i][buy][cap] =max(prices[i] + dp[i+1][1][cap-1],dp[i+1][0][cap]);
    //             }
    //         }
    //     }
    //     return dp[0][1][2];
    //     // return solve(0,1,2,prices,dp);
    // }

     int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>curr(2,vector<int>(3,0)),next(2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy)
                        curr[buy][cap] = max(-prices[i] + next[0][cap],next[1][cap]);
                    else
                        curr[buy][cap] =max(prices[i] + next[1][cap-1],next[0][cap]);
                }
            }
            next=curr;
        }
        return next[1][2];
    }
};