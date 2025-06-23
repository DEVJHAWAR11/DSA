class Solution {
public:
    void solve(int start,vector<int>candidates,int target,int &sum,vector<int>&op,vector<vector<int>>&ans){
        if(target==sum){
            ans.push_back(op);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(sum < target){
                op.push_back(candidates[i]);
                sum+=candidates[i];
                solve(i,candidates,target,sum,op,ans);
                op.pop_back();
                sum-=candidates[i];
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>op;
        int sum=0;
        solve(0,candidates,target,sum,op,ans);
        return ans;
    }
};