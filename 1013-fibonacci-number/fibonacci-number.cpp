// class Solution {
// public:
//     int fib(int n) {
        
//         if(n==0 || n==1) return n;

//         int ans=fib(n-1)+fib(n-2);
//         return ans;
//     }
// };

class Solution {
public:
    int solveRecMemo(int n , vector<int>&dp){
        //base case
        if(n==0 || n==1) return n;
        
        //step3: if already solved then return it
        if(dp[n]!=-1) return dp[n]; 

        //step2: store and return dp
        dp[n]= solveRecMemo(n-1,dp)+solveRecMemo(n-2,dp);
        return dp[n]; 
    }

    int fib(int n) {
        //step1: Create a DP array
        vector<int>dp(n+1,-1);
        int ans=solveRecMemo(n,dp);
        return ans;
    }
};