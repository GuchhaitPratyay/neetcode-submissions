class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //Building a hash set from the input - O(n) average.
        //This dedupes and gives O(1) membership checks.
        unordered_set<int> sequence(nums.begin(), nums.end());

        int longest = 0;


        for (auto i : sequence) {
            if (sequence.count(i-1) == 0) {
                int current = i;
                int length = 1;

                while (sequence.count(current + 1) > 0) {
                    ++current;
                    ++length;
                }
                longest = max(longest, length);
            }
           
        }

        return longest;
    }
};
