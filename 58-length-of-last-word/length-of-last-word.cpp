class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i=s.size()-1,count=0;
        
        while(i >=0 && s[i]==' '){
            i--;
        }
        while(i >=0 && isalpha(s[i])){
            count++;
            i--;
        }
        return count;
    }
};