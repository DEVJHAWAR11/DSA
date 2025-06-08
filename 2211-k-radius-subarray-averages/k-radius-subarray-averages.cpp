class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int i=0,j=0,newK=2*k+1;
        long long sum=0;
        vector<int>ans(nums.size(),-1);
        while(j < nums.size()){
            sum+=nums[j];
            if(j-k < 0) ans[j]=-1;
            

            if(j-i+1 < newK) j++;
            else if(j-i+1 == newK){
                ans[j-k]=(sum/newK);
                sum-=nums[i];
                i++,j++;
            }
        }
        return ans;
    }
};