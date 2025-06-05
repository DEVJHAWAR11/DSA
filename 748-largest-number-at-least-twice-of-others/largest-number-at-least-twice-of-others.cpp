class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxi = -1, index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                index = i;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i == index) continue; // skip the max element itself
            if (maxi < 2 * nums[i]) {
                return -1; // as soon as we find a violation, return -1
            }
        }

        return index;
    }
};
