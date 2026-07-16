class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> myMap;

        for (auto& element : nums) {
            myMap[element]++;
            if (myMap[element] > 1) return true;
        }

        return false;
    }
};