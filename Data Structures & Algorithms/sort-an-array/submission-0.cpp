class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int x : nums) {
            minHeap.push(x);
        }

        int i = 0;
        while (!minHeap.empty() && i < nums.size()) {
            nums[i++] = minHeap.top();
            minHeap.pop();
        }

        return nums;
    }
};