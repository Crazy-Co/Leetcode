class Solution {
public:
    int getSum(int a, int b) {
        // 2 = 010
        // 3 = 011
        // -------
        // & = 010
        // ^ = 001
        // 5 = 101

        while(b !=0){
            unsigned  int tmp = (a & b);
            a = a ^ b;
            b = tmp << 1;
        }
        return a;
    }
};