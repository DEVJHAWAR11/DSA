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
        vector<pair<int,int>> numsWithoriIndex;

        for(int i=0;i<nums.size();i++){
            numsWithoriIndex.push_back({nums[i],i});
        }

        sort(numsWithoriIndex.begin(),numsWithoriIndex.end());

        int l=0;
        int h=numsWithoriIndex.size()-1;


        while(l<h){
            int sum=numsWithoriIndex[l].first+numsWithoriIndex[h].first;

            if(sum==target)
                return {numsWithoriIndex[l].second,numsWithoriIndex[h].second};
            else if(sum>target)
                h--;
            else 
                l++;
        }
        return {};

    }
};