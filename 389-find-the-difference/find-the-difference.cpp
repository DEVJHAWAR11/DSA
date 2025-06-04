class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s=="") return t[0];

        unordered_map<char,int>mpp;
        for(auto ch : t){
            mpp[ch]++;
        }
        for(auto ch : s){
            mpp[ch]--;
            if(mpp[ch]==0)
                mpp.erase(ch);
        }
        return mpp.begin()->first;

    }
};