class Solution {
public:
    int maxVowels(string s, int k) {
        int i=0,j=0,count=0,maxi=0;
        while(j < s.size()){
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ) count++;
            if(j-i+1 < k) j++;
            else if(j-i+1 == k){
                maxi=max(count,maxi);
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) count--;
                i++,j++;
            }
        }
        return maxi;
    }
};