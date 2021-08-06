#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
/* 利用rbegin和rend
class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
    vector<int> result;
    ListNode *p = head;
    while (p != nullptr) {
      result.push_back(p->val);
      p = p->next;
    }
    return vector<int>(result.rbegin(), result.rend());
  }
};  */

// 利用栈进行辅助
class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
    stack<int> stacktmp;
    vector<int> result;
    ListNode* p = head;
    while (p != nullptr) {
      stacktmp.push(p->val);
      p = p->next;
    }
    while (!stacktmp.empty()) {
      result.push_back(stacktmp.top());
      stacktmp.pop();
    }
    return result;
  }
};
int main() {
  return 0;
}