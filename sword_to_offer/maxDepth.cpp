#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 深度优先遍历
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(dfs(root->left), dfs(root->right)) + 1;
  }
  int dfs(TreeNode* root) {
    if (root == nullptr)  return 0;
    return max(dfs(root->left), dfs(root->right)) + 1;
  }
};
// 层序遍历
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr)  return 0;
    queue<TreeNode*> que;
    que.push(root);
    int res = 0;
    while (!que.empty()) {
      queue<TreeNode*> tmp;
      int len = que.size();
      for (int i = 0; i < len; i++) {
        TreeNode* node = que.front();
        que.pop();
        if (node->left) tmp.push(node->left);
        if (node->right) tmp.push(node->right);
      }
      res++;
      que = tmp;
    }
    return res;
  }
};