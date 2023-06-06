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

/**
 * @brief 
 * 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
 * 
 * 使用中序遍历访问二叉树，得到升序序列
 */
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

    // 递归查找最左节点
    if (cur->left != nullptr)
      dfs(cur->left);

    // pre节点还没有初始化，说明此时是第一个节点
    if (pre == nullptr) {
      head = cur;
    }
    else {
      // pre right指针指向当前节点
      pre->right = cur;
    }

    // 当前节点设置
    cur->left = pre;
    pre = cur;

    // 查找右子树
    if (cur->right)
      dfs(cur->right);
  }
  Node* pre = nullptr;  // des栈中当前节点的前一个节点，即当前节点左子树的最右节点
  Node* head = nullptr;  // 返回头，实际为最左叶子节点
};