class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1; // edge case

        int mask = 0, m = n;

        while (m) {
            m = m >> 1;
            mask = (mask << 1) | 1;
        }
        n = (~n)&mask;
        return n;
    }
};
