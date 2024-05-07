/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
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
    void Reverse(ListNode* Start, ListNode* End)
    {
        if (Start == End)
            return;
        Reverse(Start->next, End);
        Start->next->next = Start;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        // left--, right--;
        // vector<ListNode*> Nodes;
        // if (left == right)
        //     return head;
        // ListNode* Loop = head;
        // while (Loop != nullptr) {
        //     Nodes.push_back(Loop);
        //     Loop = Loop->next;
        // }
        // Reverse(Nodes[left], Nodes[right]);
        // if (left == 0 && right == Nodes.size() - 1) {
        //     head = Nodes[right];
        //     Nodes[left]->next = nullptr;
        // }
        // else if (left == 0 && right != Nodes.size() - 1) {
        //     Nodes[0]->next = Nodes[right + 1];
        //     head = Nodes[right];
        // } else if (left != 0 && right == Nodes.size() - 1) {
        //     Nodes[left - 1]->next = Nodes[right];
        //     Nodes[left]->next = nullptr;
        // } else {
        //     Nodes[left - 1]->next = Nodes[right];
        //     Nodes[left]->next = Nodes[right + 1];
        // }
        // return head;
        // OFFICIAL: 一次遍历 设置DummyNode
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* Pre = Dummy;
        for (int i = 0; i < left - 1; i++) {
            Pre = Pre->next;
        }
        ListNode* Cur = Pre->next;
        ListNode* Next;
        for (int i = 0; i < right - left; i++) {
            Next = Cur->next;
            Cur->next = Next->next;
            Next->next = Pre->next;
            Pre->next = Next;
        }
        return Dummy->next;
    }
};
// @lc code=end
int main()
{
    Solution().reverseBetween(new ListNode(3, new ListNode(5)), 1, 2);
}