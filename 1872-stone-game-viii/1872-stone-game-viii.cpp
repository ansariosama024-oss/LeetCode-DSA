class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        // Prefix sum
        for (int i = 1; i < n; i++) {
            stones[i] += stones[i - 1];
        }

        // Base case
        int dp = stones[n - 1];

        // Reverse DP
        for (int i = n - 2; i > 0; i--) {
            dp = max(dp, stones[i] - dp);
        }

        return dp;
    }
};