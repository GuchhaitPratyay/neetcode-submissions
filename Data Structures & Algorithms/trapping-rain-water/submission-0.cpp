class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();

        if (len == 0) return 0;

        vector<int> prefixMax(len);
        vector<int> suffixMax(len);
        prefixMax[0] = height[0];
        suffixMax[len-1] = height[len-1];

        for (int i = 1; i < len; ++i) {
            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }

        for (int i = len-2; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }

        int totalWater = 0;
        for (int i = 0; i < len; ++i) {
            totalWater += min(prefixMax[i], suffixMax[i]) - height[i];
        }

        return totalWater;
    }
};
