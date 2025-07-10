// class Solution {
// public:
//     void solve(vector<int>& nums, int start, vector<vector<int>>& ans,vector<bool>&used) {
//         if (start == nums.size()) {
//             ans.push_back(nums);
//             return;
//         }

//         unordered_set<int> used;  // Set for current recursion level

//         for (int i = start; i < nums.size(); i++) {
//             if (used.count(nums[i])) continue;  // Skip duplicates
//             used.insert(nums[i]);

//             swap(nums[start], nums[i]);
//             solve(nums, start + 1, ans);
//             swap(nums[start], nums[i]);
//         }
//     }

//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>> ans;
//         sort(nums.begin(), nums.end());  // Optional: helps group duplicates
//         solve(nums, 0, ans);
//         return ans;
//     }
// };

class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans,vector<bool>&used,vector<int>&path) {
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue; 
            if(i>0 && nums[i-1]==nums[i] && !used[i-1]) continue;
            used[i]=true;
            path.push_back(nums[i]);
            solve(nums, ans, used, path);
            path.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool>used(nums.size(),false);
        vector<int>path;
        sort(nums.begin(), nums.end());  // Optional: helps group duplicates
        solve(nums, ans, used, path);
        return ans;
    }
};