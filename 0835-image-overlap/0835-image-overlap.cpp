class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> v1, v2;

        // Collect coordinates of all 1s
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) v1.push_back({r, c});
                if (img2[r][c] == 1) v2.push_back({r, c});
            }
        }

        // Count frequency of each translation vector (dr, dc)
        // Since -n < dr < n and -n < dc < n, size 2*n x 2*n is sufficient
        int count[61][61] = {0};
        int maxOverlap = 0;

        for (const auto& [r1, c1] : v1) {
            for (const auto& [r2, c2] : v2) {
                int dr = r2 - r1 + n;
                int dc = c2 - c1 + n;
                count[dr][dc]++;
                maxOverlap = max(maxOverlap, count[dr][dc]);
            }
        }

        return maxOverlap;
    }
};