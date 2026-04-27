class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bit_vector;
        
        for (int i = 0; i <= n; ++i) {
            int noOfSetBits = 0;
            int number = i;
            while (number) {
                number = number & (number-1);
                noOfSetBits++;
            }
            bit_vector.push_back(noOfSetBits);
        }

        return bit_vector;
    }
};
