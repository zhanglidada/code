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

/**
 * @brief 
 * 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
 * 如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
 * 
 */
class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    return dfs(root) != -1;
  }

  // dfs的返回值为-1 表示当前节点不为平衡二叉树
  int dfs(TreeNode* root) {
    if (root == nullptr)  return 0;

    int leftDepth = dfs(root->left);
    if (leftDepth == -1)  return -1;

    int rightDepth = dfs(root->right);
    if (rightDepth == -1)  return -1;
 
    return abs(leftDepth - rightDepth) < 2 ? max(leftDepth, rightDepth) + 1 : -1;
  }
};