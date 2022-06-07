#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*******************************************************************************************
 * Purpose:
 * 给定一个已排序的链表的头head,删除所有重复的元素,使每个元素只出现一次.
********************************************************************************************/


/*******************************************************************************************
 * Notes:
 * 1. 就是链表的按序插入
 * 2. 使用hash记录元素唯一性，仅插入当前未出现过的元素
********************************************************************************************/
class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr || head->next == nullptr) return head;

      ListNode  new_head = ListNode();
      ListNode* curr_node = &new_head;

      while (head) {
        // 当前元素的值第一次出现
        if (!hash_set.count(head->val)) {
          hash_set.insert(head->val);
          curr_node->next = head;
          curr_node = head;
        }
        head = head->next;
        curr_node->next = nullptr;
      }
      return new_head.next;
    }
  private:
    // 记录值的唯一性
    unordered_set<int> hash_set;
};

/*******************************************************************************************
 * Notes:
 * 1. 就是链表的按序插入
 * 2. 仅仅使用一次遍历即可，同时判断当前节点值以及下一个节点的值
********************************************************************************************/
class Solution {
  public:
    ListNode* deleteDuplicates(ListNode* head) {
      if (head == nullptr || head->next == nullptr) return head;
      
      ListNode* cur = head;  // 当前遍历的节点位置
      
      // 下一个节点存在则继续循环
      while (cur->next) {
        // 当前节点和下一个节点值相等
        if (cur->val == cur->next->val) {
          cur->next = cur->next->next;
        } else {
          cur = cur->next;
        }
      }

      return head;
    }
};