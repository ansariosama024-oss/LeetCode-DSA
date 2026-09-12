class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // start, end, weight, original index
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending time
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        // prev[i] = first interval after all intervals
        // that end before a[i] starts
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            int lo = 0, hi = i - 1;
            int ans = -1;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][1] < a[i][0]) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            prev[i] = ans + 1;
        }

        // dp[k][i] = {maximum score, lexicographically smallest indices}
        vector<vector<long long>> dp(5, vector<long long>(n + 1, 0));

        vector<vector<vector<int>>> chosen(
            5,
            vector<vector<int>>(n + 1)
        );

        for (int k = 1; k <= 4; k++) {
            for (int i = 1; i <= n; i++) {

                // Option 1: don't take current interval
                long long skipScore = dp[k][i - 1];
                vector<int> skip = chosen[k][i - 1];

                // Option 2: take current interval
                int idx = i - 1;

                long long takeScore =
                    dp[k - 1][prev[idx]] + a[idx][2];

                vector<int> take = chosen[k - 1][prev[idx]];
                take.push_back(a[idx][3]);

                // Indices must be sorted for lexicographical comparison
                sort(take.begin(), take.end());

                if (takeScore > skipScore) {
                    dp[k][i] = takeScore;
                    chosen[k][i] = take;
                }
                else if (takeScore < skipScore) {
                    dp[k][i] = skipScore;
                    chosen[k][i] = skip;
                }
                else {
                    // Same score -> choose lexicographically smaller
                    dp[k][i] = takeScore;

                    if (take < skip)
                        chosen[k][i] = take;
                    else
                        chosen[k][i] = skip;
                }
            }
        }

        return chosen[4][n];
    }
};