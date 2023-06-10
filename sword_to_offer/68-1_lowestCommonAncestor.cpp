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
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 
 * 公共祖先的定义：
 * 对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 */

// 递归对其进行判断
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != nullptr) {
      // p，q节点均在当前节点的左子树中
      if (root->val > p->val && root->val > q->val)  root = root->left;
      // p，q节点均在当前节点的右子树中
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