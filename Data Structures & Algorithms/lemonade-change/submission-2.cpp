class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        //int lemonadePrice = 5;
        //int amountWithShopKeeper = 0;
        int changeCount5 = 0;
        int changeCount10 = 0;

        for (auto& bill : bills) {
            if (bill == 5) {
                changeCount5++;
            }
            if (bill == 10) {
                changeCount10++;
                changeCount5--;
            }
            if (bill == 20) {
                if (changeCount10 > 0) {
                    changeCount10--;
                    changeCount5--;
                } else {
                    changeCount5 -= 3;
                }
            }

            if (changeCount5 < 0) {
                return false;
            }
        }

        return true;
    }
};