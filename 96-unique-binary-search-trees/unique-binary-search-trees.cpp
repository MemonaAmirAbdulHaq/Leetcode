class Solution {
public:
    int numTrees(int n) {
      vector<int> dp(n + 1, 0);

    
    dp[0] = 1; // Empty tree
    dp[1] = 1; // Single node tree

    
    for (int i = 2; i <= n; ++i) { // Number of nodes in the tree
        for (int j = 1; j <= i; ++j) { // Pick the root node
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }

    return dp[n];   
    }
};