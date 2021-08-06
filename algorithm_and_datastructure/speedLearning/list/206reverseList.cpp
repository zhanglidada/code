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
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr)  return head;
    // prev保存反转后即将指向的指针
    ListNode* prev = nullptr;
    ListNode* tmp;
    while (head != nullptr) {
      // tmp保存临时的后位指针，防止修改后链表后置无法找到
      tmp = head->next;
      head->next = prev;
      // prev移动
      prev = head;
      head = tmp;
    }
    return prev;
  }
};