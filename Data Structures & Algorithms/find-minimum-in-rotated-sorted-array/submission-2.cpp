class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size()-1;
        int result = nums[low];

        while (low <= high) {
            if (nums[low] < nums[high]) {
                result = min(result, low);
                break;
            }

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
