// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int i=0,j=0,count=0,sum=0;
//         while(j < nums.size()){
//             sum+=nums[j];
//             if(sum > k){
//                 while(sum > k){
//                     sum-=nums[i];
//                     i++;
//                 }
//             }
//             if(sum==k){
//                 count++;
//             }
//             j++;
//         }
//         return count;
//     }
// };


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }

        unordered_map<int,int>mpp;
        mpp[0]=1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mpp.find(prefix[i]-k)!=mpp.end()){
                cnt+=mpp[prefix[i]-k];
            }
            mpp[prefix[i]]++;
        }
        return cnt;
    }
};