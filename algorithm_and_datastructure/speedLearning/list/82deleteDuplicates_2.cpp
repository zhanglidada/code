#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 此处是用一个链表节点的判断来记录是否重复
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr)  return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    // tmp指向当前不重复的最后一个元素
    ListNode* tmp = dummy;
    while (tmp->next) {
      // 可能重复的节点的第一个位置
      ListNode* start = tmp->next;
      ListNode* end = tmp->next->next;
      while (end && end->val == start->val) {
        end = end->next;
      }
      if (end == start->next)
        tmp = tmp->next;
      else
        tmp->next = end;
    }
    return dummy->next;
  }
};

//  也可以用一个值记录节点是否重复，来进行后续的删除
class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr)  return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    // tmp指向当前不重复的最后一个元素
    ListNode* tmp = dummy;
    while (tmp->next && tmp->next->next) {
      if (tmp->next->next->val == tmp->next->val) {
        // 更新要删除的节点值
        rmVal = tmp->next->val;
        while (tmp->next && tmp->next->val == rmVal) {
          tmp->next = tmp->next->next;
        }
      } else {
        tmp = tmp->next;
      }
    }
    return dummy->next;
  }
  int rmVal = 0;
};