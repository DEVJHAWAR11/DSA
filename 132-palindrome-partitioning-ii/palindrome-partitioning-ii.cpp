// class Solution {
// public:
//     int dp[2001][2001];
//     int isPalindrome(string &s,int i ,int j){
//         if(i==j) return true;
//         if(i>j) return true;
//         while(i<=j){
//             if(s[i]!=s[j]) return false;
//             else i++,j--;
//         }
//         return true;
//     }

//     int solve(string &s,int i ,int j){
//         if(i>=j) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(isPalindrome(s,i,j)) return 0;

//         int mini=INT_MAX;
//         int left,right=0;

//         for(int k=i;k<=j-1;k++){
//             if(dp[i][k]!=-1)
//                 left=dp[i][k];
//             else{
//                 left=solve(s,i,k);
//                 dp[i][k]=left;
//             }
//             if(dp[k+1][j]!=-1)
//                 right=dp[k+1][j];
//             else{
//                 right=solve(s,k+1,j);
//                 dp[k+1][j]=right;
//             }
//             int tempAns=1+left+right;
            
//             mini=min(mini,tempAns);
//         }
//         return dp[i][j] = mini;
//     }

//     int minCut(string s) {
//         memset(dp,-1,sizeof(dp));
//         int n=s.size();
//         int i=0,j=n-1;
//         return solve(s,i,j);
//     }
// };

class Solution
 {
 	public:
 	int dp[2001][2001];
 	bool isPalindrome(string &s, int i, int j)
 	{
 		while (i < j)
 		{
 			if (s[i] != s[j])
 			{
 				return false;
 			}

 			i++;
 			j--;
 		}

 		return true;
 	}

 	int solve(string &s, int i, int j)
 	{
 		if (i >= j)
 			return 0;

 		if (dp[i][j] != -1)
 			return dp[i][j];

 		if (isPalindrome(s, i, j))
 			return 0;

 		int ans = INT_MAX;
 		for (int k = i; k < j; k++)
 		{
 			if (isPalindrome(s, i, k))       //if left is palindrome then only see ofr right
 			{
 				ans = min(ans, 1 + solve(s, k + 1, j));
 			}
 		}

 		return dp[i][j] = ans;
 	}

 	int minCut(string s)
 	{
 		int i = 0;
 		int j = s.length() - 1;
 		memset(dp, -1, sizeof(dp));
 		return solve(s, i, j);
 	}
 };