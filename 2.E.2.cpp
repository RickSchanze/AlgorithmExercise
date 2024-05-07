/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode* LoopNode = new ListNode(0, nullptr);
        ListNode* ResNode = LoopNode;
        ListNode* L1Node = l1;
        ListNode* L2Node = l2;
        int Carry = 0;
        while (L1Node != nullptr && L2Node != nullptr) {
            int Current = L1Node->val + L2Node->val + Carry;
            L1Node->val = Current % 10;
            Carry = Current / 10;
            LoopNode->next = L1Node;
            LoopNode = LoopNode->next;
            L1Node = L1Node->next;
            L2Node = L2Node->next;
        }
        while (L1Node != nullptr) {
            int Current = L1Node->val + Carry;
            L1Node->val = Current % 10;
            Carry = Current / 10;
            LoopNode->next = L1Node;
            LoopNode = LoopNode->next;
            L1Node = L1Node->next;
        }
        while (L2Node != nullptr) {
            int Current = L2Node->val + Carry;
            L2Node->val = Current % 10;
            Carry = Current / 10;
            LoopNode->next = L2Node;
            LoopNode = LoopNode->next;
            L2Node = L2Node->next;
        }
        if (Carry != 0) {
            LoopNode->next = new ListNode(Carry);
        }
        return ResNode->next;
    }
};
// @lc code=end
int main()
{
    Solution().addTwoNumbers(new ListNode(2, new ListNode(4, new ListNode(3))), new ListNode(5, new ListNode(6, new ListNode(4))));
}