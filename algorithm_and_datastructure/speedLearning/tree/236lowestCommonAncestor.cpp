#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 自底向上从叶子节点开始更新，所以肯定是深度最深的最近公共祖先先被访问到
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return dfsFunc(root, p, q);
  }
  // 采用分治法
  TreeNode* dfsFunc(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 如果节点为空，直接返回
    if (root == nullptr)  return root;
    // 包含了找到p或q节点；或者p为q的父亲节点，q为p的父亲节点
    if (root == p || root == q)  return root;
    TreeNode* left = dfsFunc(root->left, p, q);
    TreeNode* right = dfsFunc(root->right, p, q);

    // 说明此节点的左右孩子分别包含p和q中的一个,一般就是p和q的最近公共祖先
    if (left && right)  return root;

    // 一般是递归的开始几层，已经不是最近公共祖先
    else if (left)  return left;
    return right;
  }
};

// 用一个hashmap存储所有节点的父节点信息
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // 根节点值对应的父节点不存在
    fatherNodes[root->val] = nullptr;
    dfs(root);
    while (p != nullptr) {
      vis[p->val] = true;
      // 向上查找
      p = fatherNodes[p->val];
    }
    while (q != nullptr) {
      if (vis[q->val])  return q;
      q = fatherNodes[q->val];
    }
    return nullptr;
  }
  // 递归并存储value --> father的键值对
  void dfs(TreeNode* root) {
    if (root->left != nullptr) {
      fatherNodes[root->left->val] = root;
      dfs(root->left);
    }
    if (root->right != nullptr) {
      fatherNodes[root->right->val] = root;
      dfs(root->right);
    }
  }
 private:
  unordered_map<int, TreeNode*> fatherNodes;
  unordered_map<int, bool> vis;
};