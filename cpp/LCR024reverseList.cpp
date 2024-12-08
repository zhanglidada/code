#include <iostream>

struct ListNode {
    int             val;
    ListNode        *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = nullptr;  // prev最终指向反转后的头节点
      ListNode* curr = head;
      ListNode* next = nullptr;

      if (head == nullptr || head->next == nullptr)
        return head;

      while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }

      return prev;
    }
};

int main(int argc, char* argv[]) {

}