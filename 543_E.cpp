/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
// 深度优先搜索
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root)
    {
        ans =1;
        // 计算每一个以当前节点为根的子树的深度 然后取其中所有的最大值
        depth(root);
        return ans - 1;
    }

    int ans;

    int depth(TreeNode* rt)
    {
        if (rt == nullptr) { // 访问到空节点返回0
            return 0;
        }
        int L = depth(rt->left);
        int R = depth(rt->right);
        ans = std::max(ans, L + R+ 1);
        return std::max(L, R) + 1;
    }
};
// @lc code=end
