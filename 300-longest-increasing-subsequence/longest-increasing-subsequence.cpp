// class Solution {
// public:
//     int solve(vector<int>&nums,int curr,int prev){
//         if(curr==nums.size()) return 0;

//         int notPick=solve(nums,curr+1,prev);  //dont pick current element 

//         int pick=0;
//         if(prev==-1 || nums[curr] > nums[prev])  //pick current element only if increasing
//             pick = 1 + solve(nums,curr+1,curr);
            

//         return max(pick,notPick);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         return solve(nums,0,-1);
//     }
// };



// // Recursive function to find the length of the longest increasing subsequence
// int solve(int idx, int prevIdx, vector<int>& nums) {
//     // \U0001f501 Base Case: If we've reached the end of the array, no more elements to consider
//     if (idx == nums.size()) return 0;

//     // ✅ Option 1: Pick the current element if it's greater than the previous one in the subsequence
//     if (prevIdx == -1 || nums[idx] > nums[prevIdx]) {
//         // Two choices:
//         // 1. Pick the current element → count 1 + recurse for next index with updated prevIdx
//         // 2. Don't pick the current element → recurse for next index with same prevIdx
//         return max(
//             1 + solve(idx + 1, idx, nums),  // pick current element
//             solve(idx + 1, prevIdx, nums)   // don't pick current element
//         );
//     } else {
//         // ❌ Option 2: Cannot pick current element → skip it
//         return solve(idx + 1, prevIdx, nums);
//     }
// }

// // Main function that initializes the recursion
// int lengthOfLIS(vector<int>& nums) {
//     // Start recursion from index 0, with no previous element chosen (prevIdx = -1)
//     return solve(0, -1, nums);
// }



// class Solution {
// public:
//     int solve(int curr, int prev, vector<int>& nums,vector<vector<int>>&dp) {
//         if (curr == nums.size()) return 0;

//         if(dp[curr][prev+1]!=-1) return dp[curr][prev+1];

//         if (prev == -1 || nums[curr] > nums[prev])
//             return dp[curr][prev+1] = max(
//                 1 + solve(curr + 1, curr, nums,dp),  
//                 solve(curr + 1, prev, nums,dp)   
//             );
//             else
//                 return dp[curr][prev+1] = solve(curr + 1, prev, nums,dp);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(0, -1, nums,dp);
//     }
// };



// class Solution {
// public:

//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,0));

//         for(int curr=n-1; curr >=0;curr--){
//             for(int prev=curr-1;prev >=-1;prev--){
//                 if(prev==-1 || nums[curr] > nums[prev]){
//                     dp[curr][prev+1]=max(1+dp[curr+1][curr+1],dp[curr+1][prev+1]);
//                 }
//                 else{
//                     dp[curr][prev+1]=dp[curr+1][prev+1];
//                 }
//             }
//         }
//         return dp[0][0];
//     }
// };


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>curr(n+1,0),next(n+1,0);

        for(int i=n-1; i>=0;i--){
            for(int prev=i-1;prev >=-1;prev--){
                if(prev==-1 || nums[i] > nums[prev]){
                    curr[prev+1]=max(1+next[i+1],next[prev+1]);
                }
                else{
                    curr[prev+1]=next[prev+1];
                }
            }
            next=curr;
        }
        return curr[0];
    }
};