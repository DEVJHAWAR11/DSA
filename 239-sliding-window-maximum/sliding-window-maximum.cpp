class Solution {
public:
    // Function to return a vector of the maximums of each sliding window of size k
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;             // Result vector to store maximums
        int n = nums.size();         // Total number of elements in the input
        int left = 0, right = 0;     // Window pointers: [left, right]

        deque<int> dq;               // Deque to store potential maximums in current window
                                     // It will store elements in decreasing order from front to back

        // Expand the window to the right until we process all elements
        while (right < n) {
            // Maintain deque: remove all elements smaller than current from the back
            // Because they cannot be the maximum if current is larger
            while (!dq.empty() && dq.back() < nums[right]) {
                dq.pop_back();
            }
            // Add current element at the back of deque
            dq.push_back(nums[right]);

            // If window size < k, just move right to expand
            if (right - left + 1 < k) {
                right++;
            }
            // When window size == k, record result and slide the window
            else if (right - left + 1 == k) {
                // The front of deque is the maximum in current window
                ans.push_back(dq.front());

                // Before sliding window, if the element leaving (nums[left])
                // is equal to the deque's front, pop it from deque
                if (dq.front() == nums[left]) {
                    dq.pop_front();
                }
                // Slide window by incrementing both pointers
                left++;
                right++;
            }
        }

        return ans;  // Return all collected window maximums
    }
};