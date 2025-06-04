class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto num : nums){
            mpp[num]++;
        }
        for(auto mp : mpp){
            if(mp.second > ceil(nums.size()/2)){
                return mp.first;
            }
        }
        return 0;
    }
};