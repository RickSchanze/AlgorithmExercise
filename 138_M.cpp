/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 随机链表的复制
 */
#include "bits/stdc++.h"
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <vector>
using namespace std;
class Node
{
  public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// @lc code=start

class Solution
{
  public:
    Node *copyRandomList(Node *head)
    {
        Node *copiedListDummy = new Node(0);
        const Node *rtn = copiedListDummy;
        Node *dummy = new Node(0);
        dummy->next = head;
        while (head)
        {
            copiedListDummy->next = new Node(head->val);
            copiedListDummy = copiedListDummy->next;
            head = head->next;
        }
        copiedListDummy = rtn->next;
        head = dummy->next;
        while (head)
        {
            int k = find(dummy, head->random);
            if (k == INT_MAX)
            {
                head = head->next;
                copiedListDummy = copiedListDummy->next;
                continue;
            }
            Node *ii = const_cast<Node *>(rtn);
            for (int i = 0; i < k; i++)
            {
                ii = ii->next;
            }
            copiedListDummy->random = ii;
            head = head->next;
            copiedListDummy = copiedListDummy->next;
            continue;
        }
        return rtn->next;
    }

    int find(Node *dummy, Node *target)
    {
        int k = 0;
        while (dummy != target)
        {
            if (dummy == nullptr)
            {
                k = INT_MAX;
            }
            dummy = dummy->next;
            k++;
        }
        return k;
    }
};
// @lc code=end
// @lc code=start
// 回溯+哈希
class BetterSolution1
{
    unordered_map<Node*, Node*> cachedNodes;
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr) return nullptr;
        if (!cachedNodes.count(head)) {
            Node* headNew = new Node(head->val);
            cachedNodes[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return cachedNodes[head];
    }
};
// @lc code=end