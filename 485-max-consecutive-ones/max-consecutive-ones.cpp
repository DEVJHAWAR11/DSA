class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count=0,maxCount=0;
        for(int num : nums){
            if(num !=1){
                maxCount=max(count,maxCount);
                count=0;
            }
            else count++;
        }
        if(count) maxCount=max(maxCount,count);
        return maxCount;
    }
};