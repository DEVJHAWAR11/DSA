class Solution {
public:
    void solve(string digits,unordered_map<char,string>mpp,vector<string>&ans,string &combo,int idx){
        if(idx==digits.size()){
            ans.push_back(combo);
            return;
        }
        char ch=digits[idx];
        string str=mpp[ch];
        for(int i=0;i<str.size();i++){
            combo+=str[i];
            solve(digits,mpp,ans,combo,idx+1);
            combo.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>mpp =
        {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        vector<string>ans;
        if(digits.size()==0) return ans;
        string combo="";
        solve(digits,mpp,ans,combo,0);
        return ans;
    }
};