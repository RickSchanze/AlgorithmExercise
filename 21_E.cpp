#include <bits/stdc++.h>
#include <cstddef>
#include <cstdio>
#include <vector>
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
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        std::vector<int> test;
        ListNode *ans, *rtn;
        if (list1 == nullptr) {
            return list2;
        }
        if (list2 == nullptr) {
            return list1;
        }
        if (list1->val <= list2->val) {
            rtn = ans = list1;
            list1 = list1->next;
        } else {
            rtn = ans = list2;
            list2 = list2->next;
        }
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                ans->next = list1;
                list1 = list1->next;
                ans = ans->next;
            } else {
                ans->next = list2;
                list2 = list2->next;
                ans = ans->next;
            }
        }
        if (list1) {
            ans->next = list1;
        } else if (list2) {
            ans->next = list2;
        }
        return rtn;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution().mergeTwoLists(
        new ListNode(1, new ListNode(2, new ListNode(4, NULL))),
        new ListNode(1, new ListNode(3, new ListNode(4))));
}