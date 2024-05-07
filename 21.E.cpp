/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* LoopNode = new ListNode();
        ListNode* ResNode = LoopNode;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                LoopNode->next = list1;
                list1 = list1->next;
            } else {
                LoopNode->next = list2;
                list2 = list2->next;
            }
            LoopNode = LoopNode->next;
        }
        LoopNode->next = list1 == nullptr ? list2 : list1;
        return ResNode->next;
    }
};
// @lc code=end
int main()
{
    Solution().mergeTwoLists(new ListNode(1, new ListNode(2, new ListNode(4))),
        new ListNode(1, new ListNode(3, new ListNode(4))));
}
