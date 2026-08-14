class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0, end = nums.size()-1;
        int result = 0, occurrence = 0;
        int temp;
        while (start < end) {
            if (nums[start] == val && nums[end] != val) {
                temp = nums[end];
                nums[end] = nums[start];
                nums[start] = temp;
                ++occurrence;
                --end;
            } else if (nums[start] == val && nums[end] == val) {
                --end;
                ++occurrence;
            } else {
                ++start;
            }
        }

        return nums.size() - occurrence;
    }
};