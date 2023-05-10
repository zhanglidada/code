#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dumy = new ListNode(0);  // 新建一个头前节点
    ListNode *cur = dumy;
    while (l1 && l2) {
      if (l1->val > l2->val) {
        cur->next = l2;
        l2 = l2->next;
      } else {
        cur->next = l1;
        l1 = l1->next;
      }
      cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dumy->next;
  }
};

// 初步优化
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 定义头指针
        ListNode*   tmpnode = new ListNode(0);
        // 冗余指针
        ListNode*   cur = tmpnode;
        // 提前返回
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
            }
            else
            {
                cur->next = l2;
                l2 = l2->next;
            }
            
            cur = cur->next;
            cur->next = nullptr;
        }

        if (l1 != nullptr)
            cur->next = l1;

        if (l2 != nullptr)
            cur->next = l2;

        return tmpnode->next;
    }
};