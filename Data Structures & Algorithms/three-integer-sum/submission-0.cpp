class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        //sort the array, which takes - O(nlogn)
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        
        
        for (int i = 0; i < nums.size(); ++i) {

            auto start = nums.begin() + i + 1;
            auto end = nums.end() - 1; 
            //--end;
            

            while (start < end) {
                if ((nums[i] + *start + *end) == 0) result.push_back({nums[i], *start, *end});

                ++start;
                --end;
            }

        }

        return result;
    }
};
