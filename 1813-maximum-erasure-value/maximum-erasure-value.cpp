class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int i=0,j=0,sum=0,ans=INT_MIN;
        while(j < nums.size()){
            mpp[nums[j]]++;
            sum+=nums[j];

            if(mpp[nums[j]] > 1){
                while(mpp[nums[j]] > 1){
                    mpp[nums[i]]--;
                    if(mpp[nums[i]]==0)
                    mpp.erase(nums[i]);
                    sum-=nums[i];
                    i++;
                } 
            }
            ans=max(ans,sum);
            j++;
        }
        return ans;
    }
};