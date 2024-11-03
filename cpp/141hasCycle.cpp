#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 首先使用hashset保存之前遍历过节点的信息
class Solution {
  public:
    bool hasCycle(ListNode *head) {
      if (head == nullptr || head->next == nullptr)
        return false;

      while (head != nullptr) {
        // 链表中存在环
        if (visited.find(head) != visited.end()) {
          return true;
        }

        visited.insert(head);
        head = head->next;
      }

      return false;
    }
  private:
    unordered_set<ListNode*> visited;
};

// 使用快慢指针遍历链表
class Solution {
  public:
    bool hasCycle(ListNode *head) {
      ListNode* fast;
      ListNode* slow;

      if (head == nullptr || head->next == nullptr)
        return false;

      fast = slow = head;
      // 如果fast 或者fast->next为空，则说明没有环
      // 因为如果链表中存在环，那么链表中不可能存在空指针
      while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
          return true;
      }

      return false;
    }
};