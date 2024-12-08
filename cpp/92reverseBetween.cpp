#include <iostream>

struct ListNode {
    int             val;
    ListNode        *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 其实就是基于基础的链表反转基础上做了一些改动
class Solution {
  public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if (head == nullptr || head->next == nullptr || left >= right)
        return head;

      // 初始时l和r均指向head
      ListNode* l = head;
      ListNode* r = head;
      ListNode* priv = nullptr;
      ListNode* next = nullptr;

      // 先获取left以及left的前一个节点，如果left是第一个节点，那么priv就是空
      for (int i = 1; i < left; i++) {
        priv = l;
        l = l->next;
      }

      r = l;
      for (int i = left; i < right; i++) {
        r = r->next;
      }
      // 如果right为最后一个节点，那么prv就指向空
      next = r->next;
      ListNode* prv = next;

      for (int i = left; i <= right; i++) {
        ListNode* tmp = l->next;
        l->next = prv;
        prv = l;
        l = tmp;
      }

      // left为第一个节点时，priv为空
      if (priv != nullptr) {
        priv->next = prv;
        return head;
      }

      return prv;
    }
};