class Solution {
public:
    int solveRec(vector<int>&nums,int n,vector<int>&dp){
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(dp[n]!=-1) return dp[n];
        return dp[n] = max(nums[n-1]+solveRec(nums,n-2,dp), solveRec(nums,n-1,dp));

    }

    int rob(vector<int>& nums) {  
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solveRec(nums,n,dp);
    }
};

//Memoisation
// class Solution {
// public:
//     int solveMemoisation(vector<int>&nums,vector<int>&dp , int i){
//         int include=0,exclude=0;
//         //base case
//         if(i >= nums.size()) return 0;

//         if(dp[i]!=-1) return dp[i];

//         include=nums[i] + solveMemoisation(nums,dp,i+2);
//         exclude = 0 + solveMemoisation(nums,dp,i+1);
//         dp[i] = max(include , exclude);
//         return dp[i];
//     }

//     int rob(vector<int>& nums) {
//         int i=0;  
//         vector<int>dp(nums.size(),-1);
//         int ans=solveMemoisation(nums,dp,i);
//         return ans;
//     }
// };


// class Solution {
// public:
//     int solveTabulation(vector<int>&nums,vector<int>&dp){
//         int include=0,exclude=0;

//         if(nums.size()==1) return nums[0];

//         dp[0]=nums[0];
//         dp[1]=max(nums[1],nums[0]);     //to handle case when two elemenst and first > second

//         for(int i=2;i<nums.size();i++){
//             include=nums[i] + dp[i-2];
//             exclude = 0 + dp[i-1];
//             dp[i] = max(include , exclude);
//         }
        
//         return dp[nums.size()-1];
//     }

//     int rob(vector<int>& nums) { 
//         vector<int>dp(nums.size(),-1);
//         int ans=solveTabulation(nums,dp);
//         return ans;
//     }
// };

// class Solution {
// public:
//     int rob(vector<int>& nums) { 
//         int prev=0,curr=0;
//         for(auto num : nums){
//             int temp=max(curr,prev+num);
//             prev=curr;
//             curr=temp;
//         }
//         return curr;
//     }
// };
