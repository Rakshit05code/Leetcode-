class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long totalSum = 0;
    long long bestProduct = 0;  // ✅ renamed

    // First DFS: calculate total sum of tree
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + getTotalSum(root->left) + getTotalSum(root->right);
    }

    // Second DFS: calculate subtree sums and max product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long left = dfs(root->left);
        long long right = dfs(root->right);

        long long subTreeSum = root->val + left + right;

        long long product = subTreeSum * (totalSum - subTreeSum);
        bestProduct = max(bestProduct, product);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return bestProduct % MOD;
    }
};
