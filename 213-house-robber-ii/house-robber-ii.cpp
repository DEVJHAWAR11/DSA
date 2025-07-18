//exclude first or exclude last

// class Solution {
// public:
//     int solve(vector<int>&nums,int i,int n,vector<int>&dp){
//         if(i >= n) return 0;
//         if(dp[i]!=-1) return dp[i];

//         return dp[i] = max(nums[i]+solve(nums,i+2,n,dp),solve(nums,i+1,n,dp));
//     }

//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         vector<int>dp1(n+1,-1),dp2(n+1,-1);
//         if(n==1) return nums[0];
//         return max(solve(nums,0,n-1,dp1),solve(nums,1,n,dp2));
//     }
// };


class Solution {
public:
    int solve(vector<int>& nums, int start, int end) {
        if (start == end) return nums[start];

        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for (int i = start + 2; i <= end; ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(
            solve(nums, 0, n - 2),  // exclude last
            solve(nums, 1, n - 1)   // exclude first
        );
    }
};
