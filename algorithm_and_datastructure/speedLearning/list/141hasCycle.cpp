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

// 采用hash方式判断
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> visited;
    while (head) {
      if (visited.count(head) == 0) {
        visited.insert(head);
        head = head->next;
      } else {
        return true;
      }
    }
    return false;
  }
};

// 采用快慢指针方式判断
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return false;
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast != slow) {
      // 快指针肯定先于慢指针指向结束位置
      if (fast == nullptr || fast->next == nullptr)  return false;
      fast = fast->next->next;
      slow = slow->next;
    }
    return true;
  }
};