class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans(nums.size(),0);
        int index=nums.size()-1,start=0,end=nums.size()-1;
        while(start <= end){
            if(abs(nums[start]) < abs(nums[end])){
                ans[index--]=nums[end]*nums[end];
                end--;
            }
            else{
                ans[index--]=nums[start]*nums[start];
                start++;
            }
        }
        return ans;
    }
};