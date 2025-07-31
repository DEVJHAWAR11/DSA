class Solution {
public:
    int solve(int idx,vector<int>&prices,int n,int buy,vector<vector<int>>&dp){
        if(idx>=n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[idx]+solve(idx+1,prices,n,0,dp),0 + solve(idx+1,prices,n,1,dp));
        }
        else{
            profit=max(prices[idx] +solve(idx+2,prices,n,1,dp),0 + solve(idx+1,prices,n,0,dp));
        }
        return dp[idx][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1)); //arr[idx][buy]

        return solve(0,prices,n,1,dp);  //initially can buy;
    }
};