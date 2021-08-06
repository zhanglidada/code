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

// 采用一个额外的数组空间
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    vector<int> nums;
    while (head) {
      nums.push_back(head->val);
      head = head->next;
    }
    int len = nums.size();
    int i = 0, j = len - 1;
    while (i < j) {
      if (nums[i++] != nums[j--])  return false;
    }
    return true;
  }
};

// 采用递归方式
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)  return true;
    frontPointer = head;
    return recursivelyCheck(head);
  }
  bool recursivelyCheck(ListNode* head){
    if (head == nullptr)  return true;

    // 如果递归过程中有值不匹配，直接层层返回false
    if (!recursivelyCheck(head->next))  return false;

    // 递归结束后返回时进行比较，同时将前向指针后移
    if (frontPointer->val != head->val)  return false;
    frontPointer = frontPointer->next;

    return true;
  }
 private:
  // 设置一个递归时候的全局正向指针
  ListNode* frontPointer = nullptr;
};

// 采用改变输入的方式
class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr)  return true;
    ListNode* mid = findMid(head);
    ListNode* midRev = reverse(mid->next);
    mid->next = nullptr;
    if (compare(head, midRev)) {
      midRev =  reverse(midRev);
      mid->next = midRev;
      return true;
    }
    return false;
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
  // 一般h1 = h2或者h1 = h2 + 1
  bool compare(ListNode* h1, ListNode* h2) {
    while (h1 && h2) {
      if (h1->val != h2->val)  return false;
      h1 = h1->next;
      h2 = h2->next;
    }
    return true;
  }
};