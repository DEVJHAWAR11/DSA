class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        for (int i : nums) sum += i;

        // Check for valid subset sum
        if (abs(target) > sum || (sum + target) % 2 != 0)
            return 0;

        int s1 = (sum + target) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(s1 + 1, 0));
        dp[0][0] = 1; // There's 1 way to make sum 0 with 0 elements

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s1; j++) {
                if (nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][s1];
    }
};
