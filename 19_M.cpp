#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode()
      : val(0), next(nullptr){} * ListNode(int x)
      : val(x),
        next(nullptr){} * ListNode(int x, ListNode *next)
      : val(x),
        next(next) {}
};

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
  bool RemoveN(ListNode *cur, ListNode *pre, int &c, int n) {
    if (cur == nullptr) {
      return false;
    }
    bool rtn = RemoveN(cur->next, cur, c, n);
    c++;
    if (c == n) {
      if (pre == nullptr) {
        // 代表是第一个节点
        return true;
      }
      pre->next = cur->next;
    }
    return rtn;
  }
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (head->next == nullptr) {
      return nullptr;
    }
    int c = 0;
    bool first = RemoveN(head, nullptr, c, n);
    if (first) {
      return head->next;
    }
    return head;
  }
};
// @lc code=end

int main(int argc, char **argv) {
  Solution().removeNthFromEnd(new ListNode(1, new ListNode(2)), 2);
}

// @lc code=start
class BetterSolution {
public:
  // 双指针 r比l快n，当r==nullptr时l刚好处于要删除的位置
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *first = head;
    ListNode *second = dummy;
    for (int i = 0; i < n; ++i) {
      first = first->next;
    }
    while (first) {
      first = first->next;
      second = second->next;
    }
    second->next = second->next->next;
    ListNode *ans = dummy->next;
    delete dummy;
    return ans;
  }
};
// @lc code=end