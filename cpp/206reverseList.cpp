#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
// 采用迭代的方式实现链表的反转
class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr || head->next == nullptr)
        return head;

      ListNode * prev = nullptr;
      ListNode * cur = head;
      // 指向cur 的下一个节点，防止cur->next更改后后续链表节点位置丢失
      ListNode * next;
      while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      }

      return prev;
    }
};
*/

// 利用栈的特性实现链表的反转
class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr || head->next == nullptr)
        return head;

      // newhead 指向反转后的链表头节点（从head->next开始）
      ListNode* newhead = reverseList(head->next);

      // 1 -> 2 <- 3 <- 4 <- 5 , 此时head为1，head->next为2
      head->next->next = head;
      head->next = nullptr;

      // 始终返回反转后的链表头节点（也就是递归最后返回的原链表中的尾节点）
      return newhead;
    }
};


