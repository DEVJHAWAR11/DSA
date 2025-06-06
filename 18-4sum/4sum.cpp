// // class Solution {
// // public:
// //     vector<vector<int>> fourSum(vector<int>& nums, int target) {
// //         vector<vector<int>>ans;
// //         sort(nums.begin(),nums.end());
// //         for(int i=0;i<nums.size()-3;i++){
// //             if(i > 0 && nums[i-1]==nums[i])
// //                 continue;
// //             for(int j=i+1;j<nums.size()-2;j++){
// //                 if(j > i+1 && nums[j]==nums[j-1]) continue;
// //                 long long Target = (long long)target - (long long)nums[i] - (long long)nums[j];
// //                 int start=j+1,end=nums.size()-1;
// //                 while(start < end){
// //                     if(nums[start]+nums[end]==Target){
// //                         ans.push_back({nums[i],nums[j],nums[start],nums[end]});
// //                         while(start < end && nums[start]==nums[start+1]) start++;
// //                         while(start < end && nums[end]==nums[end-1]) end--;
// //                         start++,end--;
// //                     }
// //                     else if(nums[start]+nums[end] < Target)
// //                         start++;
// //                     else
// //                         end--;
// //                 }
// //             }
// //         }
// //         return ans;
// //     }
// // };


// //Optimized Approach using two pointer - O(n^3) time and O(n) space
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         set<vector<int>> s;
//         vector<vector<int>> output;
//         for (int i = 0; i < nums.size(); i++){
//             for(int j = i+1; j < nums.size(); j++){
//                 int k = j + 1;
//                 int l = nums.size() - 1;
//                 while (k < l) {
//                     //by writing below 4 statement this way it will not give runtime error
//                     long long int sum = nums[i];
//                     sum += nums[j];
//                     sum += nums[k];
//                     sum += nums[l];
//                     if (sum == target) {
//                         s.insert({nums[i], nums[j], nums[k], nums[l]});
//                         k++;
//                         l--;
//                     } else if (sum < target) {
//                         k++;
//                     } else {
//                         l--;
//                     }
//                 }
//             }
//         }
//         for(auto quadruplets : s)
//             output.push_back(quadruplets);
//         return output;
//     }
// };


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int k = j+1, l = n-1;
                while(k<l)
                {
                    long long curr_target = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                    if(curr_target == (long long)target)
                    {
                        result.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++,l--;
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--; 
                    }
                    else if(curr_target>target) l--;
                    else k++;
                }
            }
        }
        return result;
    }
};