class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;
        

        for (int i = 0; i < nums.size(); ++i) {
            int product = 1;
            for (int j = 0; j < nums.size(); ++j) {
                if (i != j) product *= nums[j];                
            }
            result.push_back(product);
        }

        return result;

    }
};
