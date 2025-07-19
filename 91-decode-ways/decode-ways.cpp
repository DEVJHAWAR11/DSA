// class Solution {
// public:
//     int solve(string s,int idx,vector<int>&dp){
//         if(idx==s.size()) return 1;

//         if(s[idx]=='0') return 0;

//         if(dp[idx]!=-1) return dp[idx];

//         int ways=solve(s,idx+1,dp);

//         if(idx+1 < s.size() && ((s[idx]=='1' && s[idx+1]<='9')  || (s[idx]=='2' && s[idx+1] <= '6')))
//             ways+=solve(s,idx+2,dp);
//         return dp[idx]=ways;
//     }

//     int numDecodings(string s) {
//         int n=s.size();
//         vector<int>dp(n+1,-1);
//         return solve(s,0,dp);
//     }
// };

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(n==0) return 0;
        

        // vector<int>dp(n+1,0); 
        //dp[i] means no of wys to decode the first i chars of string s
        int prev2=1;
        int prev1=s[0]=='0'? 0 : 1;  //first char
        int curr=0;

        for(int i=2;i<n+1;i++){
            curr=0;
            if(s[i-1]!='0'){    //will only take from prev char if it is valid
                curr+=prev1;
            }
            int num=stoi(s.substr(i-2,2));
            if(num>=10 && num<=26){
                curr+=prev2;
            }
            prev2=prev1;
            prev1=curr;
        }
        return prev1;  
    }
};