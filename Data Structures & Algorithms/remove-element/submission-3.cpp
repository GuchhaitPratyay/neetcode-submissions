class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0, end = nums.size();
        while (start < end) {
            if (nums[start] == val) {
                nums[start] = nums[--end];
            } else {
                ++start;
            }
        }

        return end;

        /*int slow = 0;

        for (int fast = 0; fast < nums.size(); ++fast) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }

        return slow;*/
    }
};