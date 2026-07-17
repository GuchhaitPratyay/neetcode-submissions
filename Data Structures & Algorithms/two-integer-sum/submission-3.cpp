class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //store <number, number's index>
        unordered_map<int, int> dictionary;

        for (int index=0; index < nums.size(); ++index) {            
            if (dictionary.count(target-nums[index])) {
                return {dictionary[target-nums[index]], index};
            }
            dictionary[nums[index]] = index;
        }

        return {};
    }
};
