class Solution {
public:
    int hammingWeight(int n) {
        int rem=0,cnt=0;
        while(n>1){
            rem=n%2;
            n=n>>1;
            if(rem==1){
                cnt++;
            }
        }
        if(n==1) cnt++;
        return cnt;
    }
};