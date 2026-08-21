class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size()-1;
        int result = INT32_MAX;

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (nums[mid] < result) {
                result = nums[mid];
            }

            if (nums[mid] >= nums[low]) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return result;
    }
};
