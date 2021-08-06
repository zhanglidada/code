#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// 采用迭代方法
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (head == nullptr)  return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    head = dummy;  // 使head指向开始反转节点的第一个
    ListNode* prev = nullptr;
    ListNode* tmp = nullptr;  // 保存下一个节点，防止链表丢失
    ListNode* next = nullptr;  // 反转时当前head节点要指向的next节点
    int i = 0;
    while (i < m) {
      prev = head;
      head= head->next;
      i++;
    }
    // 记录中间的节点
    ListNode* mid = head;
    // 遍历之后： 1(pre)->2(head)->3->4->5->NULL
    int j = m;
    // 如果n大于节点数，则只反转到末尾节点
    while (head != nullptr && j <= n) {
      tmp = head->next;
      head->next = next;
      next = head;
      head = tmp;
      j++;
    }
    // 循环结束后将反转的链表进行拼接
    mid->next = head;
    prev->next = next;

    return dummy->next;
  }
};

// 采用递归的方法
class Solution {
 public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (m == 1) {
      // 相当于反转链表开始的n个元素
      return reverseN(head, n);
    }
    head->next = reverseBetween(head->next, m - 1, n - 1);
    return head;
  }
  // 反转前n个节点
  ListNode* reverseN(ListNode* head, int n) {
    // 递归到最后一个节点，直接返回
    if (n == 1) {
      successor = head->next;
      return head;
    }
    // last在所有递归中均指向第n个节点，之后层层返回,即最终得到的首节点就是第n个节点
    ListNode* last = reverseN(head->next, n - 1);
    // 递归的过程中，head节点都会暂时指向successor节点，并在递归返回到上一个递归后纠正
    head->next->next = head;
    head->next = successor;
    return last;
  }
 private:
  // successor指向的是第n+1个节点
  ListNode* successor = nullptr;
};