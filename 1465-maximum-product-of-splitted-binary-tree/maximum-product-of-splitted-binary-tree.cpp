/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     vector<long long> sums;
    static const int MOD = 1e9 + 7;

    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long sum =
            root->val +
            dfs(root->left) +
            dfs(root->right);

        sums.push_back(sum);
        return sum;
    }

    int maxProduct(TreeNode* root) {
        long long total = dfs(root);
        long long ans = 0;

        for (long long s : sums) {
            ans = max(ans, s * (total - s));
        }
        return ans % MOD;
        
    }
};