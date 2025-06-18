// class Solution {
// public:
//     void solve(string ip,string op,unordered_set<string>&res){
//         if(ip.size()==0){
//             res.insert(op);
//             return;
//         }
//         string op1=op;
//         string op2=op;
//         if(islower(ip[0])){
//             op1+=ip[0];
//             op2+=toupper(ip[0]);
//         }
//         else if(isupper(ip[0])){
//             op1+=ip[0];
//             op2+=tolower(ip[0]);
//         }
//         if(isdigit(ip[0])){
//             op1+=ip[0];
//             op2+=ip[0];
//         }
//         ip.erase(ip.begin());

//         solve(ip,op1,res);
//         solve(ip,op2,res);
//     }

//     vector<string> letterCasePermutation(string s) {
//         unordered_set<string>res;
//         string op="";
//         solve(s,op,res);
//         vector<string>ans(res.begin(),res.end());
//         return ans;
//     }
// };


class Solution {
public:
    void solve(string ip,string op,vector<string>&res){
        if(ip.size()==0){
            res.push_back(op);
            return;
        }
        string op1=op;
        string op2=op;
        if(isalpha(ip[0])){
            op1+=tolower(ip[0]);
            op2+=toupper(ip[0]);

            ip.erase(ip.begin());
            solve(ip,op1,res);
            solve(ip,op2,res);
        }
        else{
            op1+=ip[0];
            ip.erase(ip.begin());
            solve(ip,op1,res);
        }
    }

    vector<string> letterCasePermutation(string s) {
        vector<string>res;
        string op="";
        solve(s,op,res);
        return res;
    }
};