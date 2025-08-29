class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int i=0,j=0,k=p.size();
        vector<int>freq(26,0) ,empty(26,0) ,ans;

        for(auto ch : p)
            freq[ch - 'a']++;
        
        while(j<s.size()){
            freq[s[j] - 'a']--;

            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                if(freq == empty) 
                    ans.push_back(i);
                freq[s[i] - 'a']++;
                i++,j++;
            }
        }
        return ans;
    }
};