class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        std::sort(nums1.begin(), nums1.end());

        int i = 0, j = 0;

        while (j < n) {
            nums1[i++] = nums2[j++];
        }
    }
};