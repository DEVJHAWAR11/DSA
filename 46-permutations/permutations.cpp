class Solution {
public:
    void solve(vector<int>&nums,int start,vector<vector<int>>&ans){
        if(start==nums.size()-1){
            ans.push_back(nums);
            return;
        }

        for(int i=start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            solve(nums,start+1,ans);
            swap(nums[start],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(nums,0,ans);
        return ans;
    }
};