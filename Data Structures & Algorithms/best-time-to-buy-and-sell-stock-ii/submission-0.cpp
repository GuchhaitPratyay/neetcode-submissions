class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0, profitSum = 0;

        int slow = 0, fast = 1;

        while (fast < prices.size()) {
            profit = prices[fast] - prices[slow];

            if (profit <= 0) {
                ++slow;
                ++fast;
            } else {
                profitSum += profit;
                slow = fast;
                ++fast;
            }
        }

        return profitSum;
    }
};