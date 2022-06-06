#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给定一个链表的头节点 head 和一个整数 val.
 * 删除链表中所有满足 Node.val == val 的节点，并返回新的头节点 。
 * Notes:
 * 
********************************************************************************************/

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*******************************************************************************************
 * Notes:
 * 采用迭代的方式
********************************************************************************************/
class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      if (head == nullptr)  return head;

      // 头节点的头节点
      ListNode  pre_head = ListNode();
      pre_head.next = head;
      ListNode* prev = &pre_head;
      ListNode* cur = pre_head.next;
      while (cur != nullptr) {
        if (cur->val == val) {
          prev->next = cur->next;
        } else {
          prev = cur;
        }
        cur = cur->next;
      }
      return pre_head.next;
    }
};


/*******************************************************************************************
 * Notes:
 * 采用递归的方式
********************************************************************************************/
class Solution {
  public:
    ListNode* removeElements(ListNode* head, int val) {
      if (head == nullptr)  return head;

      if (head->val == val) 
        return removeElements(head->next, val);
      else {
        head->next = removeElements(head->next, val);
        return head;
      }
    }
};