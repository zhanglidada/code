#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 头插法
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* cur = nullptr, *pre = head;
    ListNode* tmp;
    while (pre) {
      tmp = pre;
      pre = pre->next;
      tmp->next = cur;
      cur = tmp;
    }
    return cur;
  }
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
      return head;
    // 层层递归返回原链表的尾节点为最终的头节点
    ListNode* cur = reverseList(head->next);

    head->next->next = head;
    head->next = nullptr;
    return cur;
  }
};
/*
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    
  }
};*/