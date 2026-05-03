class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //sort the array, which takes - O(nlogn)
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        
        
        for (int i = 0; i < nums.size(); ++i) {
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            auto start = nums.begin() + i + 1;
            auto end = nums.end() - 1; 
            //--end;
            

            while (start < end) {
                int sum = (nums[i] + *start + *end);
                if (sum == 0) {

                
                    result.push_back({nums[i], *start, *end});

                    ++start;
                    --end;
                    // skip duplicate start / end after a match
                    while (start < end && *start == *(start - 1)) ++start;
                    
                
                    while (start < end && *end   == *(end   + 1)) --end;
                } else if (sum < 0) {
                    ++start;
                } else {
                    --end;
                }
            }

        }

        return result;
    }
};
