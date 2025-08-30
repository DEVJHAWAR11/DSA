class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cost=0,i=0,j=0,ans=0;
        while(j < s.size()){
            cost+=abs(s[j] - t[j]);

            while(cost > maxCost){
                cost=cost - abs(s[i] - t[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};