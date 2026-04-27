class Solution {
public:
    int hammingWeight(uint32_t n) {
        int number_of_set_bits = 0;
        while (n > 0) {
            n = n & (n-1);
            number_of_set_bits++;
        }
        return number_of_set_bits;
    }
};
