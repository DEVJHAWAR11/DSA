class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1) return nums[0];
        for(int i : nums){
            ans^=i;
        }
        return ans;
    }
};