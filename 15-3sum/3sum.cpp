// //Optimized Approach - O(n^2 logn + nlogn) - o(n^2 logn) time and O(n) space
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int target = 0;
//         sort(nums.begin(), nums.end());
//         set<vector<int>> s;
//         vector<vector<int>> output;
//         for (int i = 0; i < nums.size(); i++){
//             int j = i + 1;
//             int k = nums.size() - 1;
//             while (j < k) {
//                 int sum = nums[i] + nums[j] + nums[k];
//                 if (sum == target) {
//                     s.insert({nums[i], nums[j], nums[k]});
//                     j++;
//                     k--;
//                 } else if (sum < target) {
//                     j++;
//                 } else {
//                     k--;
//                 }
//             }
//         }
//         for(auto triplets : s)
//             output.push_back(triplets);
//         return output;
//     }
// };


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            // Skip duplicate elements for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int start = i + 1, end = nums.size() - 1;

            while (start < end) {
                int sum = nums[start] + nums[end];
                if (sum == target) {
                    ans.push_back({nums[i], nums[start], nums[end]});
                    
                    // Skip duplicates for start and end
                    while (start < end && nums[start] == nums[start + 1]) start++;
                    while (start < end && nums[end] == nums[end - 1]) end--;
                    
                    start++;
                    end--;
                }
                else if (sum < target) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        return ans;
    }
};
