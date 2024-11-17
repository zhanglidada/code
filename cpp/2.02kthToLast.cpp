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

/*
// 使用hash表或者数组
class Solution {
  public:
    int kthToLast(ListNode* head, int k) {
        vector<ListNode*> vec;

        for (auto p = head; p != nullptr; p = p->next)
          vec.push_back(p);

        return vec[vec.size() - k]->val;
    }
};
*/

//先遍历链表获得长度n，然后再遍历链表，第 n - k + 1 个就是倒数第k个节点
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
      int n = 0;

      for (auto p = head; p != nullptr; p = p->next)
        n ++;

      int pos = 1;
      auto p = head;
      // 因为从前向后和从后向前遍历需要的哪个节点会存在重复，所有 + 1
      for (p = head; p != nullptr && pos < n - k + 1; p = p->next)
        pos++;

      return p->val;
    }
};


// 使用双指针的方法
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
      auto fast = head;
      auto slow = head;

      // 先走k - 1 步
      for (auto i = 1; i < k; i ++)
        fast = fast->next;

      while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
      }

      return slow->val;
    }
}; 