class Solution {
public:
    int hammingWeight(int n) {
        int cnt=0;
        while(n>1){        //ya toh zero hoga ya toh 1 last mei n
            if(n&1)      //if n odd then rem=1 hoga
                cnt++;
            n=n>>1;
        }
        if(n==1) cnt++;
        return cnt;
    }
};