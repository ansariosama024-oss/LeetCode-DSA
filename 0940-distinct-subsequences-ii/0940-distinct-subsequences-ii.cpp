class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        int n = s.size();

        vector<long long> dp(n + 1, 0);
        vector<int> last(26, -1);

        // Empty subsequence
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {

            int ch = s[i - 1] - 'a';

            // Include or exclude current character
            dp[i] = (2 * dp[i - 1]) % MOD;

            // If character appeared before, remove duplicates
            if (last[ch] != -1) {
                dp[i] -= dp[last[ch]];

                if (dp[i] < 0)
                    dp[i] += MOD;
            }

            last[ch] = i - 1;
        }

        // Remove empty subsequence
        return (dp[n] - 1 + MOD) % MOD;
    }
};