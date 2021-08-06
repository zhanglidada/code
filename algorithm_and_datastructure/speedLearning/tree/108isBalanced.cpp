#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 采用分治的方法
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    return maxDepth(root) == -1 ? false : true;
  }
  int maxDepth(TreeNode* root) {
    if (root == nullptr)  return 0;
    int leftLen = maxDepth(root->left);
    int rightLen = maxDepth(root->right);
    if (leftLen == -1 || rightLen == -1)
      return -1;
    if (abs(leftLen - rightLen) > 1)
      return -1;
    return max(leftLen, rightLen) + 1;
  }
};