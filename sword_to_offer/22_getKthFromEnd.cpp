#include <iostream>
#include <vector>
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
  ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* fast = head;
    ListNode* slow = head;

    // 先移动第一个指针到第k个位置
    for (int i = 0; i < k; i++) {
        fast = fast->next;
    }

    // 前后指针一起移动
    while (fast) {
      fast = fast->next;
      slow = slow->next;
    }
    return slow;
  }
};