class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*sort(nums.begin(), nums.end());
        return nums[nums.size()/2];*/

        //Boyer-Moore Majority Vote
        int candidate = 0, count = 0;
        for (int i : nums) {
            if (count == 0) candidate = i;
            count += (i == candidate) ? 1 : -1;
        }

        return candidate;
    }
};