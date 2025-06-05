class Solution {
public:
    string toLowerCase(string s) {
        string str="";
        for(auto ch : s){
            str+=tolower(ch);
        }
        return str;
    }
};