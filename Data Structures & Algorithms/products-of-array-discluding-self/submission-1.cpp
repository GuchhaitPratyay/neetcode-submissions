class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //Intution
        //compute pre-fix product and su-fix product
        vector<int> preffixProduct(nums.size(), 1);
        vector<int> suffixProduct(nums.size(), 1);

        for (int i = 1; i < nums.size(); ++i) {
            preffixProduct[i] = nums[i-1] * preffixProduct[i-1];
        }

        for (int i = nums.size()-2; i >= 0; --i) {
            suffixProduct[i] = nums[i+1] * suffixProduct[i+1];
        } 

        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = preffixProduct[i] * suffixProduct[i];
        }

        return nums;
    }
};
