class Solution {
public:
    void solve(int start, int n, vector<int>& op, vector<vector<int>>& ans,int k){
        if(op.size()==k && n==0){
            ans.push_back(op);
            return;
        }

        for(int i=start;i<=9;i++){
            op.push_back(i);
            solve(i+1,n-i,op,ans,k);
            op.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> op;
        solve(1, n, op, ans,k);
        return ans;
    }
};