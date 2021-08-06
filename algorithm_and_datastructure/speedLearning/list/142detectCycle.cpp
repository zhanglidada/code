#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 利用hash表实现
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr)  return head;
    unordered_set<ListNode*> visited;
    while (head) {
      if (visited.count(head))  return head;
      visited.insert(head);
      head = head->next;
    }
    return nullptr;
  }
};

// 使用快慢指针
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if (head == nullptr)  return head;
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      // fast和slow先进行一步
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        slow = head;
        // 第一次相遇后，两个指针均每次移动一步
        while (slow != fast) {
          fast = fast->next;
          slow = slow->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};