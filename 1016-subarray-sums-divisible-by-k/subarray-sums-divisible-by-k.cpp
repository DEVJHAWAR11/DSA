class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix=0,cnt=0;
        unordered_map<int,int>mpp;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            prefix+=nums[i];
            int mod=prefix % k;
            if(mod < 0) mod=mod+k;
            if(mpp.find(mod)!=mpp.end()){
                cnt+=mpp[mod];
            }
            mpp[mod]++;
        }
        return cnt;
    }
};