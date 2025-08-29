class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>freq(26,0),empty(26,0);
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }

        int k= s1.size(),j=0,i=0;
        while(j<s2.size()){
            freq[s2[j]-'a']--;
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                if(freq == empty) return true;
                
                freq[s2[i]-'a']++;
                i++,j++;

            }
        }
        return false;
    }
};
