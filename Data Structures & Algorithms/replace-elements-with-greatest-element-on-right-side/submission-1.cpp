class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        
        vector<int> ans(arr.size());
        int rightMax = -1;
        
        for (int i = arr.size()-1; i >= 0; --i) {
            ans[i] = rightMax;
            
            rightMax = max(rightMax, arr[i]);
        }
        return ans;
    }
};