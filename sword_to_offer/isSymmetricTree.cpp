#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isSymmetric(TreeNode* root) {
    // 根节点玮空，直接玮true
    return root == nullptr ? true : recur(root->left, root->right);
  }
  bool recur(TreeNode* left, TreeNode* right) {
    // 判断边界条件
    if (left == nullptr&& right == nullptr)  return true;
    if (left == nullptr || right == nullptr || left->val != right->val)  return false;
    return recur(left->left, right->right) && recur(left->right, right->left);
  }
};