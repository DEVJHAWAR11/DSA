class Solution {
public:
    bool isPalindrome(string s,int start,int end){
        while(start <=end){
            if(s[start]!=s[end])
                return false;
            start++,end--;
        }
        return true;
    }

    void solve(string s ,vector<vector<string>>&ans,vector<string>&path,int start){
        if(start==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                path.push_back(s.substr(start,i-start+1));
                solve(s,ans,path,i+1);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(s,ans,path,0);
        return ans;
    }
};