#include <bits/stdc++.h>
#include <cstddef>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    unordered_set<ListNode *> seen;
    while (head != NULL) {
      if (seen.count(head)) {
        return head;
      }
      seen.insert(head);
      head = head->next;
    }
    return nullptr;
  }
};
// @lc code=end

class BetterSolution {
public:
  // 快慢指针
  // 从相遇点到入环点的距离加上 n−1
  // 圈的环长，恰好等于从链表头部到入环点的距离。
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    while (fast != nullptr) {
      slow = slow->next;
      if (fast->next == nullptr) {
        return nullptr;
      }
      fast = fast->next->next;
      if (fast == slow) {
        ListNode *ptr = head;
        while (ptr != slow) {
          ptr = ptr->next;
          slow = slow->next;
        }
        return ptr;
      }
    }
    return nullptr;
  }
};
