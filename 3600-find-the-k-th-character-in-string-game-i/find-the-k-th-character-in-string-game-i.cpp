class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k){
            int len=word.size();
            for(int i=0;i<len;i++){
                word+=word[i]+1;
            }
        }
        return word[k-1];
    }
};