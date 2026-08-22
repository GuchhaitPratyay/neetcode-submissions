class Solution {
private:
    void dfs(vector<int>& nums, vector<int>& current, int target, int index) {
        //base case
        if (target == 0) {
            result.push_back(current);
            return;
        }


        //backtracking logic, when the element taken is not valid
        if (index >= nums.size() || target < 0) {
            return;
        }

        //self work
        //include the current element and try to calculate the combinaitons of target
        current.push_back(nums[index]);
        
        //resursive intuition
        dfs(nums, current, target-nums[index], index);
        
        //calculate the combination skipping the current index
        current.pop_back();
        dfs(nums, current, target, index + 1);        
    }
public:
    vector<vector<int>> result;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
       
       //maintain a vector to add all the elements which sums upto the target
       vector<int> current;
       //recursively call a dfs funtion to calculate all the combinaitons of target sum
        dfs(nums, current, target, 0);
        return result;
    }
};
