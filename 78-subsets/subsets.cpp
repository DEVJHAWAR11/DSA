class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        for(int num=0;num<(1<<nums.size());num++){
            temp={};
            for(int i=0;i<nums.size();i++){
                if(num&(1<<i))
                    temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};