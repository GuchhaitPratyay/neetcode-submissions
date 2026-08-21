class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;

        while (low < high) {
            //calculate mid
            int mid = low + (high - low)/2;
            //if the target is found return the index
            if (nums[mid] == target) {
                return mid;
            } 
            
            if (nums[low] <= nums[mid]) {
                if (target > nums[mid] || target < nums[low]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                if (target < nums[mid] || target > nums[high]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            //(nums[mid] > target && target < nums[high]) {
            //    low = mid + 1;
            //} else if (nums[mid] > target && target > nums[high]) {
            //    high = mid-1;
            //} else if (nums[mid] < target && target > nums[high]) {
            //    low = mid + 1;
            //} else if (nums[mid] < target && target < nums[high]) {
            //    high = mid-1;
            //} else {
            //    break;
            //}
        }

        return -1;
    }
};
