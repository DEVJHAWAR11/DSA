// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         //brute force
//         int n= nums.size();
//         int maxi=INT_MIN,sum=0;
//         for(int i=0 ; i< n;i++){
//             for(int j=i;j<n;j++){
//                 sum=0;
//                 for(int k=i;k<=j;k++){
//                     sum+=nums[k];
//                     maxi=max(sum,maxi);
//                 }
//             }
//         }
//         return maxi;
//     }
// };

//better
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         //brute force
//         int n= nums.size();
//         int maxi=INT_MIN,sum=0;
//         for(int i=0 ; i< n;i++){
//             sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=nums[j];
//                 maxi=max(sum,maxi);
//             }
//         }
//         return maxi;
//     }
// };

//kadane algo
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //brute force
        int n= nums.size();
        int maxSum=INT_MIN,currSum=0;
        for(int num : nums){
            currSum+=num;
            maxSum=max(currSum,maxSum);
            if(currSum < 0) currSum=0;   //next iter start with new fresh subarray
        }
        return maxSum;
    }
};
