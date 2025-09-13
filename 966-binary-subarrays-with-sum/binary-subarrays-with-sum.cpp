class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prefix=0,cnt=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            if(mpp.find(prefix-goal)!=mpp.end()){
                cnt+=mpp[prefix-goal];
            }
            mpp[prefix]++;
        }
        return cnt;
    }
};