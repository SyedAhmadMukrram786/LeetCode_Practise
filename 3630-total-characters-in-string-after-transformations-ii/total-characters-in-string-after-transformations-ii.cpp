class Solution {
    using Matrix = vector<vector<long long>>;
    const int MOD = 1e9 + 7;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        Matrix res(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i)
            for (int k = 0; k < 26; ++k)
                if (A[i][k])
                    for (int j = 0; j < 26; ++j)
                        res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
        return res;
    }

    Matrix power(Matrix base, long long exp) {
        Matrix result(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i)
            result[i][i] = 1;
        while (exp) {
            if (exp % 2)
                result = multiply(result, base);
            base = multiply(base, base);
            exp /= 2;
        }
        return result;
    }

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<long long> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;

        Matrix M(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i)
            for (int j = 1; j <= nums[i]; ++j)
                M[(i + j) % 26][i]++;

        Matrix Mt = power(M, t);

        long long result = 0;
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                result = (result + Mt[i][j] * freq[j]) % MOD;

        return result;
    }
};