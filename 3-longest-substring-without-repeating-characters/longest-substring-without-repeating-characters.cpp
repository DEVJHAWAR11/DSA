class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,maxi=0;
        unordered_map<char,int>mpp;
        while(j < s.size()){
            mpp[s[j]]++;
            if(mpp.size() < j-i+1){
                while(mpp.size() < j-i+1){
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0)
                        mpp.erase(s[i]);
                    i++;
                }
            }
            if(mpp.size()==j-i+1)
                maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};