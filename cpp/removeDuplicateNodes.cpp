#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode* removeDuplicateNodes(ListNode* head) {
    if (head == nullptr)
      return nullptr;
    unordered_set<int> hashSet;
    hashSet.insert(head->val);
    ListNode* pos = head;
    while (pos->next != nullptr) {
      // 可能要被删除的节点
      ListNode* cur = pos->next;
      // 若cur指向的节点为重复节点
      if (hashSet.find(cur->val) != hashSet.end()) {
        pos->next = cur->next;
      } else {
        hashSet.insert(cur->val);
        pos = cur;
      }
    }
    return head;
  }
};
int main() {
  return 0;
}