class Solution {
public:
    int solve(string s,int idx,vector<int>&dp){
        if(idx==s.size()) return 1;

        if(s[idx]=='0') return 0;

        if(dp[idx]!=-1) return dp[idx];

        int ways=solve(s,idx+1,dp);

        if(idx+1 < s.size() && ((s[idx]=='1' && s[idx+1]<='9')  || (s[idx]=='2' && s[idx+1] <= '6')))
            ways+=solve(s,idx+2,dp);
        return dp[idx]=ways;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(s,0,dp);
    }
};