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
    // 根节点为空，直接return true
    return root == nullptr ? true : recur(root->left, root->right);
  }
  bool recur(TreeNode* left, TreeNode* right) {
    // 判断边界条件
    if (left == nullptr&& right == nullptr)  return true;
    if (left == nullptr || right == nullptr || left->val != right->val)  return false;
    return recur(left->left, right->right) && recur(left->right, right->left);
  }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        if (root == nullptr)
            return true;

        return ismirror(root->left, root->right);
    }

    bool ismirror(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr)
            return true;

        if (left == nullptr || right == nullptr)
            return false;

        if (left->val != right->val)
            return false;
        
        return ismirror(left->left, right->right) && ismirror(left->right, right->left);
    }
};