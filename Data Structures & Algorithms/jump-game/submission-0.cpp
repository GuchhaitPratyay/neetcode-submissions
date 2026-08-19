class Solution {
public:
    bool canJump(vector<int>& nums) {
        int position = 0;

        while (position < nums.size()-1) {
            if (nums[position] == 0) {
                return false;
            }
            position += nums[position];
        }

        return position == nums.size()-1 ? true : false;
    }
};
