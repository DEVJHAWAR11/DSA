// class Solution {   
// public:
//     void solve(vector<int>&nums,int start,vector<vector<int>>&ans,unordered_map<int,int>&mpp){
//         if(start==nums.size()-1){
//             ans.push_back(nums);
//             return;
//         }

//         for(int i=start;i<nums.size();i++){
//             if(mpp.find(nums[i])==mpp.end()){
//                 mpp[nums[i]]=1;
//                 swap(nums[start],nums[i]);
//                 solve(nums,start+1,ans,mpp);
//                 swap(nums[start],nums[i]);
//             }
            
//         }
//     }

//     vector<vector<int>> permuteUnique(vector<int>& nums) {
//         vector<vector<int>>ans;
//         unordered_map<int,int>mpp;
//         solve(nums,0,ans,mpp);
//         return ans;
//     }
// };

class Solution {
public:
    void solve(vector<int>& nums, int start, vector<vector<int>>& ans) {
        if (start == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;  // Set for current recursion level

        for (int i = start; i < nums.size(); i++) {
            if (used.count(nums[i])) continue;  // Skip duplicates
            used.insert(nums[i]);

            swap(nums[start], nums[i]);
            solve(nums, start + 1, ans);
            swap(nums[start], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());  // Optional: helps group duplicates
        solve(nums, 0, ans);
        return ans;
    }
};
