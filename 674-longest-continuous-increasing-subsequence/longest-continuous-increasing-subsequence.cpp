class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int count = 1, ans = 1;
        for(int i = 1, n = nums.size(); i < n; ++i){
            if(nums[i - 1] < nums[i]){
                ++count;
                ans = max(ans , count);
            }
            else count = 1;
        }
        return ans;
    }
};
