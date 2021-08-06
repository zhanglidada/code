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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* tmpHead = new ListNode(0);
    ListNode* cur = tmpHead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr) {
      int x = l1 != nullptr ? l1->val : 0;
      int y = l2 != nullptr ? l2->val : 0;
      int sum = x + y + carry;
      carry = sum / 10;
      sum %= 10;
      cur->next = new ListNode(sum);
      if (l1) l1 = l1->next;
      if (l2) l2 = l2->next;
      cur = cur->next;
    }
    // 注意最后的进位溢出情况
    if (carry > 0) cur->next = new ListNode(carry);
    return tmpHead->next;
  }
};