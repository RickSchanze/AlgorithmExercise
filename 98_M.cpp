/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include "bits/stdc++.h"
#include <climits>
#include <ostream>
#include <stack>
using namespace std;
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
    bool helper(TreeNode* root, long long lower, long long upper)
    {
        if (root == nullptr) return true;
        if (root->val <= lower || root->val >= upper) return false;
        return helper(root->left, lower, root->val) &&
            helper(root->right, root->val, upper);
    }

    bool isValidBST(TreeNode* root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
// @lc code=end

// 二叉搜索树中序遍历为递增序列
class BetterSolution {
public:
    bool isValidBST(TreeNode* root)
    {
        stack<TreeNode*> stack;
        long long inorder = (long long )INT_MIN - 1;
        while (!stack.empty() || root != nullptr) {
            while (root != nullptr) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            // 如果中心遍历节点小于等于前一个inorder说吧不是二叉搜索树
            if (root->val <= inorder) {
                return false;
            }
            inorder = root->val;
            root = root->right;
            std::cout << inorder << std::endl;
        }
        return true;
    }
};

int main()
{
    BetterSolution().isValidBST(new TreeNode(5, new TreeNode(4), new TreeNode(7, new TreeNode(6), new TreeNode(8))));
}
