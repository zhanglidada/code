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
// 将链表中的元素值放入数组中，然后首尾双向比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
      vector<int> nums;
      int i,j;

      for (auto p = head; p != nullptr; p = p->next) {
        nums.push_back(p->val);
      }

      i = 0, j = nums.size() - 1;
      while (i < nums.size() && j >= 0 && i <= j) {
        if (nums[i] != nums[j])
          return false;

        i++;
        j--;
      }

      return true;
    }
};
*/

// 使用双指针，将后半个链表反转，之后和前半个链表进行比较
// 时间复杂度不变，空间复杂度降至1
class Solution {
  public:
    bool isPalindrome(ListNode* head) {
      ListNode* slow = head;
      ListNode* fast = head;

      if (head == nullptr || head->next == nullptr)
        return true;

      while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
      }

      // 奇数个节点，将slow继续后移一个
      if (fast != nullptr)
        slow = slow->next;

      ListNode* prev = nullptr;
      ListNode* cur = slow;
      ListNode* next = nullptr;

      while (cur != nullptr) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      }

      slow = prev;
      fast = head;

      while (slow != nullptr) {
        if (slow->val != fast->val)
          return false;

        fast = fast->next;
        slow = slow->next;
      }

      return true;
    }
};