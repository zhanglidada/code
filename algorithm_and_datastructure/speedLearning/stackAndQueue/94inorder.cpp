#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* 最简单也是最常见的做法，递归
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    dfs(root);
    return res;
  }
  void dfs(TreeNode* root) {
    if (root == nullptr)  return;
    dfs(root->left);
    res.push_back(root->val);
    dfs(root->right);
    return;
  }
 private:
  vector<int> res;
}; */

// 可以利用一个栈来保存访问路径，并且根据出栈的顺序不同可以返回序列
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr)  return res;
    stack<TreeNode*> path;
    path.push(root);
    root = root->left;
    while (!path.empty() || root) {
      if (root) {
        path.push(root);
        root = root->left;
      } else {
        TreeNode* tmp = path.top();
        path.pop();
        res.push_back(tmp->val);
        root = tmp->right;
      }
    }
    return res;
  }
};