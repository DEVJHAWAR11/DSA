class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int prefix=0;
        for(int i=0;i<nums.size();i++){
            int rsum=total-nums[i]-prefix;
            if(rsum==prefix) return i;
            prefix+=nums[i];
        }
        return -1;
    }
};