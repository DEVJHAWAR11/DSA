class Solution {
public:
    void solve(int start,vector<int>& candidates, int target, vector<int> &op, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(op);
            return;
        }
        if(target < 0) return;
        for(int i=start;i<candidates.size();i++){
            if(i > start && candidates[i]==candidates[i-1]) continue;
            if(candidates[i] > target) return;
            op.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],op,ans);
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        solve(0, candidates, target, op, ans);
        return ans;
    }
};