class Solution {
public:
    bool isPalindrome(string s) {
        if(s.size()==1) return true;
        string newStr;
        for(auto ch : s){
            if(isalpha(ch) || isdigit(ch))
                newStr+=tolower(ch);
            else
                continue;
        }
        
        int i=0,j=newStr.size()-1;
        while(i <=j){
            if(newStr[i]!=newStr[j])
                return false;
            i++,j--;
        }
        return true;
    }
};