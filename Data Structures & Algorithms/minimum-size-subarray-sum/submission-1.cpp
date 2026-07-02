class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0, end = 0;
        int runningSum = 0;
        int minWindow = INT32_MAX;

        while (end < nums.size()) {
            runningSum += nums[end];
                while (runningSum >= target) {
                    minWindow = min(minWindow, (end-start+1));
                    runningSum -= nums[start++];  
                }                   
            ++end;            
        }

        return minWindow == INT32_MAX ? 0 : minWindow;
    }
};