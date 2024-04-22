#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr) {} * ListNode(int x)
        : val(x)
        , next(nullptr) {} * ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};
/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* f = dummy;
        while (f->next != nullptr && f->next->next != nullptr) {
            ListNode* n3 = f->next->next->next;
            ListNode* n2 = f->next->next;
            f->next->next->next = f->next;
            f->next->next = n3;
            f->next = n2;
            f = f->next->next;
        }
        return dummy->next;
    }
};
// @lc code=end

int main(int argc, char** argv)
{
    Solution().swapPairs(new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5))))));
}
