class Solution {
public:
    unordered_map<int,int> map;
    int majorityElement(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++) if(++map[nums[i]] > nums.size() / 2) return nums[i];

        return 0;
    }
};