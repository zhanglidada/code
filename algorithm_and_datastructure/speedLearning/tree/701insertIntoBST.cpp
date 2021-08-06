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

// 递归的方式
class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
      root = new TreeNode(val);
      return root;
    }
    if (root->val > val)
      root->left = insertIntoBST(root->left, val);
    else
      root->right = insertIntoBST(root->right, val);
    return root;
  }
};

// 非递归的方式
class Solution {
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr)
      return new TreeNode(val);

    TreeNode* pos = root;
    while (pos != nullptr) {
      if (val > pos->val) {
        if (pos->right == nullptr) {
          pos->right = new TreeNode(val);
          break;
        } else {
          pos = pos->right;
        }
      }
      else {
        if (pos->left == nullptr) {
          pos->left = new TreeNode(val);
          break;
        } else {
          pos = pos->left;
        }
      }
    }
    return root;
  }
};