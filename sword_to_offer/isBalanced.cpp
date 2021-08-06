#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
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
  bool isBalanced(TreeNode* root) {
    return dfs(root) != -1;
  }
  int dfs(TreeNode* root) {
    if (root == nullptr)  return 0;
    int leftDepth = dfs(root->left);
    if (leftDepth == -1)  return -1;
    int rightDepth = dfs(root->right);
    if (rightDepth == -1)  return -1;
    return abs(leftDepth - rightDepth) < 2 ? max(leftDepth, rightDepth) + 1 : -1;
  }
};