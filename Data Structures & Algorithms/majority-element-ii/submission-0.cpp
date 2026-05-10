class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> myMap;

        for (int x : nums) {
            myMap[x]++;
        }
        int count = nums.size()/3;
        for (const auto& [key, value] : myMap) {
            if (value > count) result.push_back(key);
        }

        return result;
    }
};