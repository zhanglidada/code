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

// 递归对其进行判断
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != nullptr) {
      if (root->val > p->val && root->val > q->val)  root = root->left;
      else if (root->val < p->val && root->val < q->val)  root = root->right;
      else break;
    }
    return root;
  }
};

// 优化，让p的值始终小于q的值，可以在循环中减少判断
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    int pvalue = min(p->val, q->val);
    int qvalue = max(p->val, q->val);
    while (root != nullptr) {
      // 小于较小的值
      if (root->val < pvalue)  root = root->right;
      // 大于较大的值
      else if (root->val > qvalue)  root = root->left;
      else break;
    }
    return root;
  }
};
// 采用递归的方式
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root->val > p->val && root->val > q->val)  return lowestCommonAncestor(root->left, p, q);
    else if (root->val < p->val && root->val < q->val)  return lowestCommonAncestor(root->right, p, q);
    return root;
  }
};