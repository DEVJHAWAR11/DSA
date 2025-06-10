class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> freq(26, 0);
        for(auto ch : s1) {
            freq[ch - 'a']++;
        }
        vector<int> freq1(26, 0);
        int i = 0, j = 0;
        while(j < s2.size()) {
            freq1[s2[j] - 'a']++;
            if(j - i + 1 < s1.size()) {
                j++;
            } else if(j - i + 1 == s1.size()) {
                if(freq == freq1) return true;
                freq1[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};
