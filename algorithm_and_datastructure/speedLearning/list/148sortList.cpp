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

// 采用递归的方式，空间复杂度是o(logn)
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    // 当前节点为空或者链表只有一个节点，直接返回
    if (head == nullptr || head->next == nullptr)  return head;
    ListNode* fast = head->next;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* tmp = slow->next;
    slow->next = nullptr;  // 将当前链表分开
    ListNode* left =  sortList(head);
    ListNode* right = sortList(tmp);

    ListNode* res = new ListNode(0);
    ListNode* h = res;
    while (left && right) {
      if (left->val < right->val) {
        h->next =left;
        left = left->next;
      } else {
        h->next = right;
        right = right->next;
      }
      h = h->next;
    }
    h->next = left == nullptr ? right : left;
    return res->next;
  }
};

// 采用迭代的方法
class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    // 当前节点为空或者链表只有一个节点，直接返回
    if (head == nullptr || head->next == nullptr)  return head;
    int length = 0, intv = 1;
    ListNode* h = head;
    // h1和h2是链表合并时候的头部
    ListNode* h1;
    ListNode* h2;
    ListNode* pre;  // 链表合并时候的辅助头部
    ListNode* res = new ListNode(0);
    // 先获取链表长度
    while (h != nullptr) {
      length++;
      h = h->next;
    }
    res->next = head;
    while (intv < length) {
      pre = res;
      // h始终指向未排序原始链表中的某一个位置
      h = res->next;
      while (h != nullptr) {
        int i = intv;
        h1 = h;
        while (i > 0 && h != nullptr) {
          h = h->next;
          i--;
        }
        // 最后一个分隔，且分割的元素个数小于intv时候，直接break
        if (i > 0)  break;

        i = intv;
        h2 = h;
        // 找到下一个迭代开始的位置，即下一个h1可能开始的位置
        while (i > 0 && h != nullptr) {
          h = h->next;
          i--;
        }
        int c1 = intv, c2 = intv - i;
        while (c1 > 0 && c2 > 0) {
          if (h1->val < h2->val) {
            pre->next = h1;
            h1 = h1->next;
            c1--;
          } else {
            pre->next = h2;
            h2 = h2->next;
            c2--;
          }
          pre = pre->next;
        }
        pre->next = c1 == 0 ? h2 : h1;
        while (c1 > 0 || c2 > 0) {
          pre = pre->next;
          c1--;
          c2--;
        }
        // 一次迭代结束后将前面拍好的链表与后面进行拼接
        pre->next = h;
      }
      intv *= 2;
    }
    return res->next;
  }
};
int main() {
  vector<int> inputs = {4,2,1,3};
  ListNode* dummy = new ListNode(0);
  ListNode* head = dummy;
  for (auto num : inputs) {
    ListNode* node = new ListNode(num);
    head->next = node;
    head = head->next;
  }
  Solution ss;
  ListNode* sortNodes =  ss.sortList(dummy->next);
  while (sortNodes) {
    cout << sortNodes->val << " ";
    sortNodes = sortNodes->next;
  }
}