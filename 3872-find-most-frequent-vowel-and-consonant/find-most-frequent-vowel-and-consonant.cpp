class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26]={0},maxVowel=0,maxConso=0;
        for(auto ch : s){
            freq[ch-'a']++;
            if(ch=='a'|| ch=='e'||ch=='i'|| ch=='o'|| ch=='u'){
                maxVowel=max(maxVowel,freq[ch-'a']);
            }
            else{
                maxConso=max(maxConso,freq[ch-'a']);
            }
        }
        return maxVowel+maxConso;
    }
};