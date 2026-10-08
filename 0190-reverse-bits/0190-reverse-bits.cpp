class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        return reverse(n, 32);
    }

    uint32_t reverse(uint32_t n, int bits) {
        if (bits == 1)
            return n & 1;

        int half = bits / 2;

        uint32_t left = n >> half;
        uint32_t right = n & ((1 << half) - 1);

        uint32_t revRight = reverse(right, half);
        uint32_t revLeft = reverse(left, half);

        return (revRight << half) | revLeft;
    }
};