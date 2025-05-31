class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> s;
        int i = 0, j = 0;
        long long sum = 0, maxi = 0;

        while (j < nums.size()) {
            // If duplicate found, shrink window from the left
            while (s.find(nums[j]) != s.end()) {
                s.erase(nums[i]);
                sum -= nums[i];
                i++;
            }

            // Add current element
            s.insert(nums[j]);
            sum += nums[j];

            // If window size is k, check and slide
            if (j - i + 1 == k) {
                maxi = max(maxi, sum);

                // Slide window forward
                s.erase(nums[i]);
                sum -= nums[i];
                i++;
            }

            j++;
        }

        return maxi;
    }
};
