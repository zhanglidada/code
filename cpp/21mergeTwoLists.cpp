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
class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      // 处理边界条件
      if (list1 == nullptr)
        return list2;
      if (list2 == nullptr)
        return list1;

      ListNode* reshead = new ListNode(0);
      ListNode* pos = reshead;

      while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
          pos->next = list1;
          list1 = list1->next;
          pos = pos->next;
        }
        else {
          pos->next = list2;
          list2 = list2->next;
          pos = pos->next;
        }
      }

      if (list1 != nullptr)
        pos->next = list1;

      if (list2 != nullptr)
        pos->next = list2;

      return reshead->next;
    }
};
*/

// 也可以使用递归的方法实现，将一个大的问题分解成小问题去解决，
// 最终解决的小问题向上返回并依次解决大问题(感觉和动态规划有点像，后续问题的结果依赖于之前问题的结果)
class Solution {
  public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      // 处理边界条件
      if (list1 == nullptr)
        return list2;
      if (list2 == nullptr)
        return list1;

      // 直接修改list1的next指针指向下一层递归的结果
      if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
      }
      else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
      }
      return nullptr;
    }
};