class Solution {
public:
    int findMin(vector<int> &nums) {
        int low = 0, high = nums.size()-1;
        int result = nums[0];

        while (low <= high) {
            //check if the array is rotated or not
            //if it is rotated then it will not go the in the if block because assumption is that 1st element in the smallest element
            if (nums[low] < nums[high]) {
                result = min(result, nums[low]);
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
