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
  ListNode* deleteNode(ListNode* head, int val) {
    if (head == nullptr)
      return head;
    if (head->val == val)
      return head->next;
    ListNode* tmp = head;
    while (tmp->next) {
      if (tmp->next->val == val) {
        tmp->next = tmp->next->next;
        break;
      }
      tmp = tmp->next;
    }
    return head;
  }
};