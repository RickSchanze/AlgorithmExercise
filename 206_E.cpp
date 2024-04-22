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
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) return nullptr;
    ListNode *l = head, *pN = head->next;
    head->next = nullptr;
    ListNode* ans = pN == nullptr ? head : pN;
    while (l != nullptr) {
      if (pN == nullptr) return ans;
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
};
// @lc code=end

int main(int argc, char** argv) {
  ListNode* Node = new ListNode(1, nullptr);
  auto ans = Solution().reverseList(Node);
  std::cout << "test";
}