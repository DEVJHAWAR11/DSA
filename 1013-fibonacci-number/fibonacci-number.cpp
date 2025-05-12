// class Solution {
// public:
//     int fib(int n) {
        
//         if(n==0 || n==1) return n;

//         int ans=fib(n-1)+fib(n-2);
//         return ans;
//     }
// };

//top-down arrproach
// class Solution {
// public:
//     int solveRecMemo(int n , vector<int>&dp){
//         //base case
//         if(n==0 || n==1) return n;
        
//         //step3: if already solved then return it
//         if(dp[n]!=-1) return dp[n]; 

//         //step2: store and return dp
//         dp[n]= solveRecMemo(n-1,dp)+solveRecMemo(n-2,dp);
//         return dp[n]; 
//     }

//     int fib(int n) {
//         //step1: Create a DP array
//         vector<int>dp(n+1,-1);
//         int ans=solveRecMemo(n,dp);
//         return ans;
//     }
// };


//tabulation method

class Solution {
public:
    int fib(int n){
        //1-->create a dp array
        vector<int>dp(n+1,-1);

        //2-->fill initial data by base case
        dp[0]=0;
        if(n==0) 
            return dp[0];
        dp[1]=1;

        //3--->fill rest of array using recursive relation
        //size -->n+1--->0 to n
        //0 ,1 filled --> so index from 2 to n
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];

    }
};


