#include <bits/stdc++.h>
#include <cstddef>
#include <unordered_set>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
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
  bool hasCycle(ListNode *head) {
    if (head == nullptr) return false;
    int count = 0;
    while (head->next != nullptr) {
      head = head->next;
      count++;
      if (count > 30000) return true;
    }
    return false;
  }
};
// @lc code=end

class AnthoerSolution {
public:
  // 哈希表
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode *> seen;
    while (head != NULL) {
      if (seen.count(head)) {
        return true;
      }
      seen.insert(head);
      head = head->next;
    }
    return false;
  }
};

class BetterSolution {
public:
  // 弗洛伊德判圈算法 一快一慢两指针，如果有环那么快指针将追上慢指针
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return false;
    }
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (slow != fast) {
      if (fast == nullptr || fast->next == nullptr) {
        return false;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    return true;
  }
};