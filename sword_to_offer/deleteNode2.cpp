#include <iostream>
#include <vector>
using namespace std;

// 删除链表中的重复节点
// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode* deleteDuplicateNode(ListNode* head) {
    if (!head)
      return head;
    ListNode* dumy = new ListNode(-1);
    // 由于删除重复节点，且重复节点不保留，所以定义虚拟头节点，防止头节点重复情况
    dumy->next = head;
    // p始终指向上一个非重复节点
    ListNode* p = dumy;
    while (p->next) {
      auto q = p->next;
      while (q && p->next->val == q->val)  q = q->next;
      if (p->next->next == q)
        p = p->next;  // p的下一个节点为非重复节点
      else  p->next = q;
    }
    return dumy->next;
  }
  ListNode* createChain(vector<int>& list) {
    if (list.empty())
      return nullptr;
    ListNode* root = new ListNode(list[0]);
    ListNode* pretmp = root;
    int len = list.size();
    for (int i = 1; i < len; i++) {
      ListNode* tmp = new ListNode(list[i]);
      pretmp->next = tmp;
      pretmp = tmp;
    }
    return root;
  }
  void print(ListNode* root) {
    while (root) {
      cout << root->val << "->";
      root = root->next;
    }
    cout << endl;
  }
};

int main() {
  vector<int> list = {1,1,1,1,2,2,2,3,4,5,6,7,7,7,7,8,8,9,9,9,9,9,10};
  Solution ss;
  ListNode* root = ss.createChain(list);
  ss.print(root);
  ListNode* deleteroot = ss.deleteDuplicateNode(root);
  ss.print(deleteroot);
  return 0;
}