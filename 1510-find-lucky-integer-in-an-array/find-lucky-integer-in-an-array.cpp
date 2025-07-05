class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>mpp;
        int ans=-1;
        for(auto num : arr){
            mpp[num]++;
        }
        for(auto num : arr){
            if(mpp[num]==num)
                ans=max(ans,num);
        }
        return ans;
    }
};