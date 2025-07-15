class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int v=0,c=0;
        for(auto ch : word){
            ch=tolower(ch);
            if(!isalnum(ch))
                return false;
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                v++;
            else if(!isdigit(ch))
                c++;
        }
        return v>0 && c>0;
    }
};