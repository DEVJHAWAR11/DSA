class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0;  // Pointer to place non-zero elements
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] != 0) { 
                swap(nums[l], nums[r]); // Swap non-zero element with left pointer
                l++; // Move left pointer forward
            }
        }
    }
};
