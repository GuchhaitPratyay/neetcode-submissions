class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;

        int leftMax = height[l], rigthMax = height[r];
        int totalWater = 0;
        while (l < r) {
            if (leftMax < rightMax) {
                ++l;
                leftMax = max(leftMax, height[l]);
                totalWater += leftMax - height[l];
            } else {
                --r;
                rightMax = max(rightMax, height[r]);
                totalWater += rightMax - height[r];
            }
        }

        return totalWater;
    }
};
