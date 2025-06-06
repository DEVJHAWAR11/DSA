class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //o(n2)
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]+nums[j]==target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};

        //two-pointer
        vector<pair<int,int>>indexElement;
        for(int i=0;i<nums.size();i++){
            indexElement.push_back({nums[i],i});
        }
        sort(indexElement.begin(),indexElement.end());

        int start=0,end=indexElement.size()-1;

        while(start < end){
            if(indexElement[start].first + indexElement[end].first == target)
                return {indexElement[start].second,indexElement[end].second};
            else if(indexElement[start].first + indexElement[end].first < target)
                start++;
            else
                end--;
        }
        return {};
    }
};