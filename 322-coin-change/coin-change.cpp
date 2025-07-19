// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n =coins.size();
//         vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
//         for(int j=1;j<amount+1;j++){
//             dp[0][j]=INT_MAX-1;
//         }
//         for(int i=0;i<n+1;i++){
//             dp[i][0]=0;
//         }

//         for(int i=1;i<n+1;i++){
//             for(int j=1;j<amount+1;j++){
//                 if(coins[i-1]<=j)
//                     dp[i][j]=min(dp[i][j-coins[i-1]]+1,dp[i-1][j]);
//                 else
//                     dp[i][j]=dp[i-1][j];
//             }
//         }
//         return dp[n][amount]==INT_MAX-1? -1 : dp[n][amount];
//     }
// };


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, INT_MAX - 1), curr(amount + 1, INT_MAX - 1);

        prev[0] = 0,curr[0] = 0;

        for (int i = 1; i <= n; i++) {
            //curr[0] = 0;
            for (int j = 1; j <= amount; j++) {
                if (coins[i - 1] <= j) {
                    curr[j] = min(curr[j - coins[i - 1]] + 1, prev[j]);
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[amount] == INT_MAX - 1 ? -1 : prev[amount];
    }
};


