class Solution {
public:
    bool isMatch(string s, string p) {
       int m = s.length(), n = p.length();

    // DP table: dp[i][j] represents whether s[0..i-1] matches p[0..j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

    // Base cases
    dp[0][0] = true; // Empty string matches empty pattern

    // Pattern with only '*' matches empty string
    for (int j = 1; j <= n; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 1];
        }
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                // '*' matches zero or more characters
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            } else if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) {
                // '?' matches a single character, or characters match
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];  
    }
};