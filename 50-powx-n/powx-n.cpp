class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long m = abs((long long)n);  // Convert to long long to handle INT_MIN safely
        
        while (m > 0) {
            if (m & 1) ans *= x;  // If the exponent is odd, multiply by `x`
            x *= x;  // Square `x`
            m >>= 1;  // Halve the exponent
        }
        
        return (n >= 0) ? ans : 1.0 / ans;
    }
};
