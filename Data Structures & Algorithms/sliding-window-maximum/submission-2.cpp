class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeapPair;
        int start = 0, end = 0;
        vector<int> result;

        while (end < nums.size()) {
            //Calculation
            //start pushing the elements in to the priority queue
            maxHeapPair.push({nums[end], end});
            if (end - start + 1 < k) {
                ++end;
            } else if (end - start + 1 == k) {
               
                while (maxHeapPair.top().second < start) {
                    maxHeapPair.pop();
                }   
                 result.push_back(maxHeapPair.top().first);             
                ++start;
                ++end;
            }

        }

        return result;
    }
};
