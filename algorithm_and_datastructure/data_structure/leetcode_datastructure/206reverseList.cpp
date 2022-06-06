#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表
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
 * 首先想到使用头插法
********************************************************************************************/
class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      if (head == nullptr)  return head;
      ListNode  new_head = ListNode();  // 创建头节点的头节点
      ListNode* curr_node = nullptr;  // 当前操作节点指针
      while (head) {
        curr_node = head;
        head = head->next;
        curr_node->next = new_head.next;
        new_head.next = curr_node;
      }
      return new_head.next;
    }
};

/*******************************************************************************************
 * Notes:
 * 其次可以使用递归
 * 假设链表的其余部分均已反转，那么将当前节点反转即可
********************************************************************************************/
class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      // 递归起始就返回，或者递归最后一层返回节点
      if (head == nullptr || head->next == nullptr)  return head;
      // 获取从下一个节点开始反转的链表的头节点，也是整个链表反转后的头节点
      ListNode* new_head = reverseList(head->next);
      head->next->next = head;
      head->next = nullptr; 
      return new_head;  // 返回始终是最终的头节点
    }
};