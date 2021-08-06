#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr)  return nullptr;
    if (key > root->val)
      root->right = deleteNode(root->right, key);
    else if (key < root->val)
      root->left = deleteNode(root->left, key);
    // 相等的时候删除当前节点
    else {
      if (root->left == nullptr && root->right == nullptr)
        root = nullptr;
      else if (root->right) {
        root->val = successor(root);
        root->right = deleteNode(root->right, root->val);
      } else {
        root->val = preDecessor(root);
        root->left = deleteNode(root->left, root->val);
      }
    }
    return root;
  }

  // 获得前驱节点的值
  int preDecessor(TreeNode* root) {
    root = root->left;
    while (root->right != nullptr)
      root = root->right;
    return root->val;
  }
  // 获得后继节点的值
  int successor(TreeNode* root) {
    root = root->right;
    while (root->left != nullptr)
      root = root->left;
    return root->val;
  }
};