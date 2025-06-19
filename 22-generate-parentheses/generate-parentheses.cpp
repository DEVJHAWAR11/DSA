class Solution {
public:
    void solve(int open,int close,string op,vector<string>&res){
        if(open==0 && close==0){
            res.push_back(op);
            return;
        }
        string op1=op;
        string op2=op;
        if(close > open){
            if(open!=0){
                op1=op1+'(';
                solve(open-1,close,op1,res);
            }
            op2=op2+')';
            solve(open,close-1,op2,res);
        }
        else{
            op1=op1+'(';
            solve(open-1,close,op1,res);
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>res;
        solve(n,n,"",res);
        return res;
    }
};