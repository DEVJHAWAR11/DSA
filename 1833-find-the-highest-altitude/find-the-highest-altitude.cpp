class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size()+1;
        vector<int>altitutes(n,0);

        for(int i=1;i<n;i++){
            altitutes[i]=altitutes[i-1] + gain[i-1];
        }
        sort(altitutes.begin(),altitutes.end());
        return altitutes[n-1];
    }
};