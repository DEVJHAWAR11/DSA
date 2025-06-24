class Solution {
public:
    void solve(int n,int k,vector<int>&op,int start,vector<vector<int>>&ans){
        if(op.size()==k){
            ans.push_back(op);
            return;
        }

        for(int i=start;i<=n;i++){
            op.push_back(i);
            solve(n,k,op,i+1,ans);
            op.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>op;
        solve(n,k,op,1,ans);
        return ans;
    }
};