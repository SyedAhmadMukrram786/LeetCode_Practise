class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long total = 1LL * n * (n + 1) / 2;
        long long countDiv = n / m;
        long long divSum = 1LL * m * countDiv * (countDiv + 1) / 2;
        return total - 2 * divSum;
    }
};