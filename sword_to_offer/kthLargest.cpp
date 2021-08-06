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
  int kthLargest(TreeNode* root, int k) {
    this->target = k;
    dfs(root);
    return res;
  }
  void dfs(TreeNode* root) {
    if (root == nullptr)  return;
    dfs(root->right);
    // 减枝
    if (target == 0)  return;
    if (--target == 0) {
      res = root->val;
      return;
    }
    dfs(root->left);
    return;
  }
 private:
  int res, target;
};