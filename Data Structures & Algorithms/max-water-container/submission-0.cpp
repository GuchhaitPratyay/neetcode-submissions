class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size()-1;
        int result = 0;
        while (left < right) {
            int area = min(heights[left], heights[right]) * (right - left);
            result = max(result, area);

            if (heights[left] <= heights[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return result;
    }
};
