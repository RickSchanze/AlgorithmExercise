/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

#include <algorithm>
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};

// @lc code=start
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

    int max = 0;

    int maxDepth(TreeNode* root)
    {
        int count = 0;
        Traverse(root, count);
        return max;
    }

    void Traverse(TreeNode* root, int count) {
        // 前序遍历
        if (root == nullptr) return;
        count++;
        if (count > max) max = count;
        Traverse(root->left, count);
        Traverse(root->right, count);
    }
};
// @lc code=end

int main() {
    Solution().maxDepth(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7))));
}

// 深度优先搜索
class BetterSolution {
public:

    int max = 0;

    int maxDepth(TreeNode* root)
    {
        if (root == nullptr) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right));
    }
};