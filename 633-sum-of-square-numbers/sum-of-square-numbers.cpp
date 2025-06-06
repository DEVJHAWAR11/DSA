class Solution {
public:
    bool judgeSquareSum(int c) {
        long start = 0, end = sqrt(c); // use long to avoid overflow
        while (start <= end) {
            long sum = start * start + end * end;
            if (sum == c)
                return true;
            else if (sum < c)
                start++;
            else
                end--;
        }
        return false;
    }
};
