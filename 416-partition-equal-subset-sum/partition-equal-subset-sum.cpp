class Solution {
public:

    // bool subsetSum(vector<int>nums,int sum,int n){
    //     if(sum==0) return true;
    //     if(n==0)  return false; 

    //     if(nums[n-1]<=sum){
    //         bool include=subsetSum(nums,sum-nums[n-1],n-1);
    //         bool exclude =subsetSum(nums,sum,n-1);
    //         return include || exclude;
    //     }
    //     else{
    //         return subsetSum(nums,sum,n-1);
    //     }
    //     return true;
    // }

    // bool subsetSum(vector<int>&nums,int sum,int n,vector<vector<int>>&dp){
    //     if(sum==0) return true;
    //     if(n==0)  return false;

    //     if(dp[n][sum]!=-1) return dp[n][sum]; 

    //     if(nums[n-1]<=sum){
    //         bool include=subsetSum(nums,sum-nums[n-1],n-1,dp);
    //         bool exclude =subsetSum(nums,sum,n-1,dp);
    //         return dp[n][sum]= include || exclude;
    //     }
    //     else{
    //         return dp[n][sum]= subsetSum(nums,sum,n-1,dp);
            
    //     }
    // }

    bool subsetSum(vector<int>nums,int sum,int n,vector<vector<int>>&dp){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                dp[i][0]=true;
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]<=j){
                    bool include=dp[i-1][j-nums[i-1]];
                    bool exclude =dp[i-1][j];
                    dp[i][j]= include || exclude;
                }
                else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(auto i : nums){
            sum+=i;
        }
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1,false));
        if(sum&1) return false;
        else return subsetSum(nums,sum/2,n,dp);
    }
};