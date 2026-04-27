class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ansVector(nums.size() * 2);
        copy(nums.begin(), nums.end(), ansVector.begin());
        int n = nums.size();
        for (int i = n; i <= (n*2)-1; ++i) {
           ansVector[i] = nums[i-n];
        }
        return ansVector;
    }
};