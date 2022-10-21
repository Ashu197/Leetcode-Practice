class Solution {
public:
    int solve(string& s, int idx, int tight, int count, vector<vector<vector<int>>>& dp) {
        if (idx == s.length()) return count;
        if (dp[idx][tight][count] != -1) return dp[idx][tight][count];
        int ans = 0, bound = 9;
        if (tight) bound = s[idx] - '0';
        for (int i = 0; i <= bound; i++) {
            int add = 0;
            if (i == 1) add = 1;
            ans += solve(s, idx + 1, tight & (i == bound), count + add, dp);
        }
        return dp[idx][tight][count] = ans;
    }
    int countDigitOne(int n) {
        string str = to_string(n);
        vector<vector<vector<int>>>dp(10, vector<vector<int>>(2, vector<int>(10, -1)));
        return solve(str, 0, 1, 0, dp);
    }
};