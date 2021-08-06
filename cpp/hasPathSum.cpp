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
/*
// DFS进行递归
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr)
      return false;
    // 遍历到了叶子节点
    if (!root->left && !root->right)
      return sum == root->val;
    else
      return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
  }
};  */

// 使用队列进行辅助，用广度优先的算法
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == nullptr)
      return false;
    queue<pair<TreeNode*, int>> BFSqueue;
    BFSqueue.push({root, root->val});
    while (!BFSqueue.empty()) {
      TreeNode* tmp = BFSqueue.front().first;
      int value = BFSqueue.front().second;
      BFSqueue.pop();
      if (!tmp->left && !tmp->right) {
        if (value == sum)
          return true;
        continue;
      }
      if (tmp->left)
        BFSqueue.push({tmp->left, tmp->left->val + value});
      if (tmp->right)
        BFSqueue.push({tmp->right, tmp->right->val + value});
    }
    return false;
  }
};
int main() {
  return 0;
}