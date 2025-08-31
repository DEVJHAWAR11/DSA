// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int Tsum;
//         for(int i=0;i<nums.size();i++){
//             Tsum+=nums[i];
//         }
//         int leftSum=0;
//         for(int i=0;i<nums.size();i++){
//             int rightSum=Tsum-leftSum-nums[i];
//             if(leftSum==rightSum)
//                 return i;

//             leftSum+=nums[i];
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prefix=0,rSum=0;
        int total=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++){
            if(i>0)  prefix+=nums[i-1]; //leftSum
            rSum=total - prefix - nums[i];
            if(rSum == prefix) return i;     
        }
        return -1;
    }
};