class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i=0,j=0,maxi=0,sum=0;
        unordered_map<int,int>mpp;
        while(j < nums.size()){
            mpp[nums[j]]++;
            sum+=nums[j];
            while(mpp[nums[j]] > 1){
                    sum-=nums[i];
                    mpp[nums[i]]--;
                    i++; 
            }
            if(mpp[nums[j]]==1)
                maxi=max(maxi,sum);
            j++;
        }
        return maxi;
    }
};