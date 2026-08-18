class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //vairable to track the how many sub-arrays are present
        int result = 0;
        //variable to store the current running sum
        int runningSum = 0;

        unordered_map<int, int> prefixSums;

        //insert one prefix sum entry in the hashmap
        prefixSums[0] = 1;

        //traverse the conplete array
        for (auto& i : nums) {
            runningSum += i;
            //Check if the difference is already present in the prefix sum map
            int difference = runningSum - k;

            result += prefixSums[difference];

            //record the sum value and increament the counter from 0 --> 1 initially
            prefixSums[runningSum]++;
        }

        return result;
    }
};