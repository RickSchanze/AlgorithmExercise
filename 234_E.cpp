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
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
  // 反转链表后判断是不是值都相等
public:
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    ListNode *l = head, *pN = head->next;
    head->next = nullptr;
    ListNode *ans = pN == nullptr ? head : pN;
    while (l != nullptr) {
      if (pN == nullptr)
        return ans;
      ListNode *t = pN->next;
      if (t == nullptr) {
        ans = pN;
      }
      pN->next = l;
      l = pN;
      pN = t;
    }
    return ans;
  }
  bool isPalindrome(ListNode *head) {
    ListNode *NewList = new ListNode(head->val, nullptr);
    ListNode* p = head, *pN = NewList;
    while (p->next != nullptr) {
      pN->next = new ListNode(p->next->val, nullptr);
      pN = pN->next;
      p = p->next;
    }
    p = reverseList(head);
    while (p != nullptr) {
      if (p->val != NewList->val) {
        return false;
      } else {
        p = p->next;
        NewList = NewList->next;
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char** argv) {
  ListNode *n =
      new ListNode(1, new ListNode(2, nullptr));
  bool rtn = Solution().isPalindrome(n);
}


class AnotherSolution {
  // 使用递归
  ListNode *frontPtr;
  bool isPalindrome(ListNode *head) {
    frontPtr = head;
    return recursivelyCheck(head);
  }

  bool recursivelyCheck(ListNode *currentNode) {
    if (currentNode != NULL) {
      if (!recursivelyCheck(currentNode->next)) {
        return false;
      }
      if (currentNode->val != frontPtr->val) {
        return false;
      }
      frontPtr = frontPtr->next;
    }
    return true;
  }
};