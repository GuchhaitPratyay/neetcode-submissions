class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int n = nums.size();

        // Pass 1: place each in-range value v at index v - 1
        for (int i = 0; i < n; ++i) {
            // Keep swapping until nums[i] is out of range
            // or already sitting in its correct home (duplicate guard).
            while (nums[i] >= 1 && nums[i] <= n
                   && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Pass 2: first seat that's wrong gives the answer
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) return i + 1;
        }

        // All seats 1..n filled → answer is n + 1
        return n + 1;
    }
};