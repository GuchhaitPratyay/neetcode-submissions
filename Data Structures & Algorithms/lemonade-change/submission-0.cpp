class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int lemonadePrice = 5;
        int amountWithShopKeeper = 0;

        for (auto& bill : bills) {
            if (bill == lemonadePrice) {
                amountWithShopKeeper += bill;
            } else {
                //given that bills can be only 5, 10, 20
                int returnAmount = bill - lemonadePrice;
                if (returnAmount > amountWithShopKeeper) {
                    return false;
                } else {
                    amountWithShopKeeper = (amountWithShopKeeper - returnAmount) + bill;
                }
            }
        }

        return true;
    }
};