class Solution {
public:
    string reversePrefix(string word, char ch) {
        int start=0,end=word.size()-1,idx=0;
        while(end>=0){
            if(word[end]==ch){
                idx=end;
            }
            end--;
        }
        end=idx;
        if(end==0) return word;
        while(start < end) swap(word[start++],word[end--]);
        return word;
    }
};