class Solution {
public:
    long long flowerGame(int n, int m) {
        //for alice to win int one lane there should be odd flower and another even flower ..
        //total pairs possible == n*m
        //exactly half of them have even odd pair ..
        return 1LL * n * m / 2;
    }
};