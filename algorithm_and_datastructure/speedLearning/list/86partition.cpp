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
  ListNode* partition(ListNode* head, int x) {
    if (head == nullptr)  return head;
    ListNode* beforeList = new ListNode(0);
    ListNode* afterList = new ListNode(0);
    ListNode* beforeHead = beforeList;
    ListNode* afterHead = afterList;
    while (head) {
      if (head->val < x) {
        beforeHead->next = head;
        beforeHead = beforeHead->next;
      } else {
        afterHead->next = head;
        afterHead = afterHead->next;
      }
      head = head->next;
    }
    afterHead->next = nullptr;
    beforeHead->next = afterList->next;
    return beforeList->next;
  }
};