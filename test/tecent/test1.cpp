#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct Node {
  int val;
  Node* next;
  Node(int value) {
    val = value;
    next = nullptr;
  }
};
Node* func(Node* head, int k) {
  Node* pre = nullptr;
  Node* tmp = head;
  while (--k) {
    pre = tmp;
    tmp = tmp->next;
  }
  pre->next = tmp->next;
  return head;
}
int main() {
  int n,k;
  cin >> n >> k;
  Node* head = new Node(0);
  Node* tmphead = head;
  while (n) {
    int value;
    cin >> value;
    Node* tmp = new Node(value);
    tmphead->next = tmp;
    tmphead = tmphead->next;
    n--;
  }
  Node* res = func(head->next, k);
  while (res) {
    cout << res->val << " ";
    res = res->next;
  }
  return 0;
}