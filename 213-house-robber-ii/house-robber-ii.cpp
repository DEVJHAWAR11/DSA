//exclude first or exclude last

class Solution {
public:
    int solve(vector<int>&nums,int i,int n,vector<int>&dp){
        if(i >= n) return 0;
        if(dp[i]!=-1) return dp[i];

        return dp[i] = max(nums[i]+solve(nums,i+2,n,dp),solve(nums,i+1,n,dp));
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp1(n+1,-1),dp2(n+1,-1);
        if(n==1) return nums[0];
        return max(solve(nums,0,n-1,dp1),solve(nums,1,n,dp2));
    }
};

