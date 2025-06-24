class Solution {
public:
    void solve(vector<int>nums,int start,vector<int>&subset,vector<vector<int>>&ans){
        ans.push_back(subset);

        for(int i=start;i<nums.size();i++){
            if(i > start && nums[i]==nums[i-1]) continue; //skip duplicates
            subset.push_back(nums[i]);
            solve(nums,i+1,subset,ans);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>subset;
        solve(nums,0,subset,ans);
        return ans;
    }
};