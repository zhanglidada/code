#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 双指针法
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* tmp1 = headA;
    ListNode* tmp2 = headB;
    while (tmp1 != tmp2) {
      tmp1 = tmp1 == nullptr ? headB : tmp1->next;
      tmp2 = tmp2 == nullptr ? headA : tmp2->next;
    }
    return tmp1;
  }
};

// 使用一个hash表，保存第一个链表中所有已经遍历过的节点
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 先添加所有的遍历节点
    while (headA)
    {
      visited.insert(headA);
      headA = headA->next;
    }

    while (headB)
    {
      if (visited.count(headB))
        return headB;
      
      headB = headB->next;
    }

    return nullptr;
  }
  unordered_set<ListNode*> visited;
};
