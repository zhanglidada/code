#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

/*******************************************************************************************
 * Purpose:
 * 将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
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
 * 采用迭代方式
********************************************************************************************/
class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (list1 == nullptr || list2 == nullptr)
        return list1 == nullptr ? list2 : list1;

      ListNode new_head = ListNode();
      ListNode* tmp = &new_head;
      while (list1 && list2) {
        if (list1->val < list2->val) {
          tmp->next = list1;
          list1 = list1->next;
        } else {
          tmp->next = list2;
          list2 = list2->next;
        }
        
        tmp = tmp->next;
      }
      // 合并结束后最多只有一个还未指向链表结尾
      tmp->next = list1 != nullptr ? list1 : list2;

      return new_head.next;
    }
};

/*******************************************************************************************
 * Notes: 
 * 采用递归方式
 * list1[0] + merge(list1[1:], list2)  list1[0] < list2[0]
 * list2[0] + merge(list1, list2[1:])  otherwise
********************************************************************************************/
class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if (list1 == nullptr || list2 == nullptr)
        return list1 == nullptr ? list2 : list1;

      if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
      } else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
      }
    }
};