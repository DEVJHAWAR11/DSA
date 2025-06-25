class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            while(nums[i]>0){
                int digit=nums[i]%10;
                sum+=digit;
                nums[i]/=10;
            }
            if(sum==i)
                mini=min(mini,i);
        }
        return mini==INT_MAX? -1 : mini;
    }
};