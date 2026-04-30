class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> maxHeap;
        vector<int> result;
        
        unordered_map<int, int> frequency;
        for (auto i : nums) frequency[i]++;

        for (auto & [key, count] : frequency) {
            maxHeap.push({count, key});
        }

        for (int i = 0; i < k; ++i) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }

        return result;
        //for (int i = 0; i < nums.size(); ++i) {
        //    int occurence = 0;
        //    for (int j = 0; j < nums.size(); ++j) {
        //        if (nums[i] == nums[j]) {
        //            ++occurence;
        //        }
        //    }
        //    frequency.insert({occurence,nums[i]});
        //}
////
        ////for (auto it = frequency.rbegin(); result.size() != k &&it != frequency.rend(); ++it) {
        ////    result.push_back(it->second);
        //    cout<<it->first<<" "<<it->second<<endl;
        //}
//
        //return result;
    }
};
