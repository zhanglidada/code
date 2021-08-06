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

// 采用分治的方法,其实就是自顶向下的方法
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;
    return dvidiveConquer(root);
  }
  int dvidiveConquer(TreeNode* root) {
    if (root == nullptr)
      return 0;
    int left = dvidiveConquer(root->left);
    int right = dvidiveConquer(root->right);
    return max(left, right) + 1;
  }
};