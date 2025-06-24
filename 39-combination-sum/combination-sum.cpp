class Solution {
public:
    void solve(int start, vector<int>& candidates, int target, vector<int>& op, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(op);
            return;
        }
        if (start >= candidates.size() || target < 0) return; // Base case

        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) continue; // Skip if current element is too large
            if (i > start && candidates[i] == candidates[i-1]) continue; // Skip duplicates
            op.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], op, ans); // Reuse allowed: pass 'i', not 'i+1'
            op.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> op;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        solve(0, candidates, target, op, ans);
        return ans;
    }
};