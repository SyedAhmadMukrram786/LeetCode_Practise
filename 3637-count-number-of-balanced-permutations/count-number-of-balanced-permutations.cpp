class Solution {
    static const int MOD = 1e9 + 7;
    using LL = long long;
    vector<LL> factorial, inverse, inverseFactorial;

    void precompute(int m) {
        factorial.assign(m + 1, 1);
        for (int i = 1; i <= m; i++)
            factorial[i] = factorial[i - 1] * i % MOD;

        inverse.assign(m + 1, 1);
        for (int i = 2; i <= m; i++)
            inverse[i] = MOD - (MOD / i) * inverse[MOD % i] % MOD;

        inverseFactorial.assign(m + 1, 1);
        for (int i = 1; i <= m; i++)
            inverseFactorial[i] = inverseFactorial[i - 1] * inverse[i] % MOD;
    }

public:
    int countBalancedPermutations(const string& input) {
        int len = input.size(), totalSum = 0;
        for (char ch : input) totalSum += ch - '0';
        if (totalSum % 2 == 1) return 0;

        precompute(len);
        int halfSum = totalSum / 2, halfLength = len / 2;
        vector<vector<int>> dp(halfSum + 1, vector<int>(halfLength + 1));
        dp[0][0] = 1;

        vector<int> digitCount(10);
        for (char ch : input) {
            int digit = ch - '0';
            digitCount[digit]++;
            for (int sum = halfSum; sum >= digit; sum--)
                for (int length = halfLength; length > 0; length--)
                    dp[sum][length] = (dp[sum][length] + dp[sum - digit][length - 1]) % MOD;
        }

        LL result = dp[halfSum][halfLength];
        result = result * factorial[halfLength] % MOD * factorial[len - halfLength] % MOD;
        for (int count : digitCount)
            result = result * inverseFactorial[count] % MOD;
        return result;
    }
};