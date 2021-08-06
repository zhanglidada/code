#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr)  return;
    ListNode* mid = findMid(head);
    ListNode* midReverse = reverse(mid->next);
    mid->next = nullptr;  // 拆分成前后两个链表
    bool flag = true;
    ListNode* dummy = new ListNode(0);
    ListNode* prehead = dummy;
    while (head && midReverse) {
      if (flag) {
        prehead->next = head;
        head = head->next;
      } else {
        prehead->next = midReverse;
        midReverse = midReverse->next;
      }
      flag = !flag;
      prehead = prehead->next;
    }
    prehead->next = head == nullptr ? midReverse : head;
    head = dummy->next;
    return;
  }
  
  ListNode* findMid(ListNode* head) {
    ListNode* fast = head->next;
    ListNode* slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
  ListNode* reverse(ListNode* head) {
    // ListNode* dummy = new ListNode(0);
    // dummy->next = head;
    ListNode* next = nullptr;
    ListNode* tmp = nullptr;
    while (head) {
      tmp = head->next;
      head->next = next;
      next = head;
      head = tmp;
    }
    return next;
  }
};

int main() {
  vector<int> inputs = {1,2,3,4,5,6,7};
  ListNode* dummy = new ListNode(0);
  ListNode* head = dummy;
  for (auto num : inputs) {
    ListNode* node = new ListNode(num);
    head->next = node;
    head = head->next;
  }
  Solution ss;
  ListNode* tmp = ss.findMid(dummy->next);
  cout << tmp->val;
  // while (head) {
  //   cout << head->val << " ";
  //   head = head->next;
  // }
}