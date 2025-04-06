class Solution {
public:

        //------------pivot approach------------------

    // int bs(vector<int>& arr, int s, int e, int x) {
    //     while (s <= e) {
    //         int mid = s + (e - s) / 2;
    //         if (arr[mid] == x)
    //             return mid;
    //         else if (arr[mid] > x)
    //             e = mid - 1;
    //         else 
    //             s = mid + 1;
    //     }
    //     return -1;
    // }

    // int find_pivot(vector<int>& nums) {
    //     int s = 0, e = nums.size() - 1;
    //     while (s <= e) {
    //         int mid = s + (e - s) / 2;
            
    //         // Ensure mid+1 and mid-1 are within bounds before accessing them
    //         if (mid+1 <nums.size() && nums[mid] > nums[mid + 1])
    //             return mid;
    //         if (mid-1 >=0 && nums[mid] < nums[mid - 1])
    //             return mid - 1;

    //         // If left part is unsorted, pivot must be there
    //         if (nums[s] > nums[mid])
    //             e = mid - 1;
    //         else // Otherwise, pivot is in the right part
    //             s = mid + 1;
    //     }
    //     return -1;
    // }

    // int search(vector<int>& nums, int target) {
    //     int n = nums.size();
    //     int pivot = find_pivot(nums);

    //     // If no pivot found, array is not rotated, perform normal binary search
    //     if (pivot == -1)
    //         return bs(nums, 0, n - 1, target);

    //     // Search in the left part of the pivot
    //     if (target >= nums[0] && target <= nums[pivot])
    //         return bs(nums, 0, pivot, target);

    //     // Otherwise, search in the right part
    //     return bs(nums, pivot + 1, n - 1, target);
    // }

    //--------------checking sorted part and then searching there 

    int search(vector<int>& nums, int target) {
    int s = 0, e = nums.size() - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        
        if (nums[mid] == target)
            return mid;
        
        // Check if the left half is sorted
        if (nums[s] <= nums[mid]) {
            if (target >= nums[s] && target < nums[mid])
                e = mid - 1;  // Search in the left half
            else
                s = mid + 1;  // Search in the right half
        } 
        // Otherwise, the right half must be sorted
        else {
            if (target > nums[mid] && target <= nums[e])
                s = mid + 1;  // Search in the right half
            else
                e = mid - 1;  // Search in the left half
        }
    }
    return -1;
}

};
