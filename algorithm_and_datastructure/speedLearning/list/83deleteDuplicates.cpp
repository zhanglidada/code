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
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == nullptr)  return head;
    ListNode* tmp = head;
    while (tmp) {
      while (tmp->next && tmp->next->val == tmp->val) {
        tmp->next = tmp->next->next;
      }
      tmp = tmp->next;
    }
    return head;
  }
};
int main() {

}