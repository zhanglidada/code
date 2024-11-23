#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <string>

struct TreeNode {
  int         val;
  TreeNode*   left;
  TreeNode*   right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  public:
  bool isSymmetric(TreeNode* root) {
    if (root == nullptr)
      return true;

    if (root->left == nullptr && root->right == nullptr)
      return true;

    return mirror(root->left, root->right);
  }

  bool mirror(TreeNode* left, TreeNode* right) {
    // 均为空true
    if (left == nullptr && right == nullptr)
      return true;
    
    // 一个空一个不空false
    if (left == nullptr || right == nullptr)
      return false;

    // 值相等进一步比较
    if (left->val == right->val)
      return mirror(left->left, right->right) && mirror(left->right, right->left);

    return false;
  }
};