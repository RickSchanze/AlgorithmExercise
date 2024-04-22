/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include "bits/stdc++.h"
#include <algorithm>
#include <queue>
#include <vector>
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

 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> ans;
        vector<vector<TreeNode*>> nodes;
        if (root == nullptr) return {};
        ans.push_back({ root->val });
        nodes.push_back({ root });
        auto last = *(nodes.end() - 1);
        while (find_if(last.begin(), last.end(), [](TreeNode* node) { return node != nullptr; }) != last.end()) {
            vector<TreeNode*> newNodes;
            vector<int> newLayer;
            for (auto& node : last) {
                if (node != nullptr) {
                    newNodes.push_back(node->left);
                    newNodes.push_back(node->right);
                    if (node->left != nullptr) {
                        newLayer.push_back(node->left->val);
                    }
                    if (node->right != nullptr) {
                        newLayer.push_back(node->right->val);
                    }
                }
            }
            nodes.push_back(newNodes);
            ans.push_back(newLayer);
            last = *(nodes.end() - 1);
        }
        if (ans.size() > 0 && ((ans.end() - 1)->size() <= 0)) {
            ans.pop_back();
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution().levelOrder(new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(8))));
}

// 广搜
class Solution1 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) {
            return ret;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector<int>{});
            for (int i = 1; i <= currentLevelSize; i++) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
    }
}