class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> maxHeap;
        int start = 0, end = 0;
        vector<int> result;

        while (end < nums.size()) {
            //Calculation
            //start pushing the elements in to the priority queue
            maxHeap.push(nums[end]);
            if (end - start + 1 < k) {
                ++end;
            } else if (end - start + 1 == k) {
                result.push_back(maxHeap.top());
                if (maxHeap.top() == nums[start]) maxHeap.pop();

                ++start;
                ++end;
            }

        }

        return result;
    }
};
