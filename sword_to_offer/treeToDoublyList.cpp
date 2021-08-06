#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (root == nullptr)  return nullptr;
    dfs(root);
    head->left = pre;
    pre->right = head;
    return head;
  }
  // 中序遍历
  void dfs(Node* cur) {
    if (cur->left)
      dfs(cur->left);
    // pre节点还没有初始化，说明此时是第一个节点
    if (pre == nullptr) {
      head = cur;
    }  else {
      pre->right = cur;
    }
    cur->left = pre;
    pre = cur;
    if (cur->right)
      dfs(cur->right);
  }
  Node* pre = nullptr, *head = nullptr;
};