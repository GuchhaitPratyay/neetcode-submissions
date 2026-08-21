class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;

        while (low < high) {
            int mid = low + (high - low)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target && target < nums[high]) {
                low = mid + 1;
            } else if (nums[mid] > target && target > nums[high]) {
                high = mid-1;
            } else if (nums[mid] < target && target > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < target && target < nums[high]) {
                high = mid-1;
            } else {
                break;
            }
        }

        return -1;
    }
};
