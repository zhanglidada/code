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

/**
 * @brief 
 * 给定一棵二叉搜索树，请找出其中第 k 大的节点的值。
 * 
 * 
 */
class Solution {
 public:
  int kthLargest(TreeNode* root, int k) {
    // target为剩余查找次数
    this->target = k;
    
    dfs(root);
    
    return res;
  }

  // 从二叉搜索树的最右节点开始深度遍历
  void dfs(TreeNode* root) { 
    if (root == nullptr)  return;
    // 先从最右叶子节点开始查找
    dfs(root->right);

    // 减枝，防止多余的dfs查找
    if (target == 0)  return;

    // 当前节点为第k大节点
    if (-- target == 0) {
      res = root->val;
      return;
    }

    // 查找当前节点的左子树
    dfs(root->left);
    return;
  }
 private:
  int res = 0;
  int target = 0;
};