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
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      // 存放链表A中所有节点的指针
      unordered_set<ListNode*> set;

      for (auto p = headA; p != nullptr; p = p->next) {
        set.insert(p);
      }

      for (auto p = headB; p!= nullptr; p = p->next) {
        if (set.find(p) != set.end()) 
          return p;
      }

      return nullptr;
    }

};
*/

// 进阶方法，时间复杂度O(n), 空间复杂度O(1)
// 可以使用双指针方法
/*
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if (headA == nullptr || headB == nullptr)
        return nullptr;

      ListNode* pa = headA;
      ListNode* pb = headB;

      //  就算两个链表不相交，最终也都会指向null，因为走了一样长的步数
      while (pa != pb) {
        pa = pa == nullptr ? headB : pa->next;
        pb = pb == nullptr ? headA : pb->next;
      }

      return pa;
    }
};
*/

// 先获取两个链表的长度，然后将较长的链表先移动差值
// 之后两个链表一起移动，直到相交节点或者链表结尾
class Solution {
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
          return nullptr;

        int lena = 0;
        int lenb = 0;
        int diff = 0;
        ListNode* pa = headA;
        ListNode* pb = headB;

        for (auto p = headA; p != nullptr; p = p->next) {
          lena ++;
        }
        for (auto p = headB; p != nullptr; p = p->next) {
          lenb ++;
        }

        diff = lena > lenb ? lena - lenb : lenb - lena;

        if (lena > lenb) {
          for (int i = 0; i < diff; i++)
            pa = pa->next;
        }
        else
        {
          for (int i = 0; i < diff; i ++)
            pb = pb->next;
        }

        while (pa != pb) {
          pa = pa == nullptr ? nullptr : pa->next;
          pb = pb == nullptr ? nullptr : pb->next;
        }

        // 最终要么是同一节点，要么是null
        return pa;
    }
};