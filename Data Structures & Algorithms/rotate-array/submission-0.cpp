class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int j = nums.size() - k;
        int i = 0;

        while (j < nums.size()) {
            swap(nums[i++], nums[j++]);
        }
    }
};