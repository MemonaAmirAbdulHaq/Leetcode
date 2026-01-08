class Solution {
public:
    vector<vector<long long>> memo;
    vector<int> a, b;
    int n, m;

    long long dfs(int i, int j) {
        if (i == n || j == m) return -1e18;
        if (memo[i][j] != -1e18) return memo[i][j];

        long long prod = 1LL * a[i] * b[j];

        long long take = max(
            prod,
            prod + dfs(i + 1, j + 1)
        );

        long long skip = max(
            dfs(i + 1, j),
            dfs(i, j + 1)
        );

        return memo[i][j] = max(take, skip);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        a = nums1; b = nums2;
        n = a.size(); m = b.size();

        memo.assign(n, vector<long long>(m, -1e18));

        return (int)dfs(0, 0);
    }
};
