class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> frequency;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int occurence = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[i] == nums[j]) {
                    ++occurence;
                }
            }
            frequency[occurence] = nums[i];
        }

        for (auto it = frequency.rbegin(); result.size() != k &&it != frequency.rend(); ++it) {
            result.push_back(it->second);
            cout<<it->first<<" "<<it->second<<endl;
        }

        return result;
    }
};
