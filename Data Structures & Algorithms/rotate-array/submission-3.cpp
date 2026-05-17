class Solution {

private:
    void reverse(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            ++left;
            --right;
        }
    }
public:
    void rotate(vector<int>& nums, int k) {
        
        //while (k--) {
        //    int temp = nums[nums.size()-1];
        //    for (int i = nums.size()-1; i > 0; --i) {
        //        nums[i] = nums[i-1];
        //    }
        //    nums[0] = temp;
        //}
        
        //reduce k if it is greater than size of nums
        int length = nums.size();
        k = k%length;
        
        reverse(nums, 0, length-1);
        reverse(nums, 0, k-1);        
        reverse(nums, k, length-1);
    }

};