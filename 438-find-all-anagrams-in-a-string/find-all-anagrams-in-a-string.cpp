class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int i=0,j=0,k=p.size();
        vector<int>freq(26,0),window(26,0);
        vector<int>ans;
        for(auto ch : p) freq[ch-'a']++;
        while(j < s.size()){
            window[s[j]-'a']++;
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                if(freq==window) ans.push_back(i);
                window[s[i]-'a']--;
                i++,j++;
            }
        }
        return ans;
    }
};