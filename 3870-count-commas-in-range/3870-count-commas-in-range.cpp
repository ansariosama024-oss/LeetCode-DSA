class Solution {
public:
    int countCommas(int n) {
        long long ans = 0;

for(int i = 1; i <= n; i++) {
    string s = to_string(i);

    if(s.size() >= 4) {
        ans += (s.size() - 1) / 3;
    }
}

return ans;
    }
};