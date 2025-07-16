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
    bool canPartition(vector<int>& nums) {
        int sum=0,n=nums.size();
        for(auto i : nums){
            sum+=i;
        }
        if(sum&1) return false;
        vector<bool>prev(sum/2+1,false);
        vector<bool>curr(sum/2+1,false);
        
        prev[0]=true;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum/2+1;j++){
                if(nums[i-1] <=j)
                    curr[j]=prev[j-nums[i-1]] || prev[j];
                else
                    curr[j]=prev[j];
            }
            prev=curr;
        }
        return prev[sum/2];
    }
};