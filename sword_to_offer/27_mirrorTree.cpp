#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//采用递归方法
class Solution {
 public:
  TreeNode* mirrorTree(TreeNode* root) {
    // 为空直接返回
    if (root == nullptr)
      return nullptr;

    // 叶子节点直接返回
    if (root->left == nullptr && root->right == nullptr)
      return root;

    TreeNode* tmp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(tmp);
    return root;
  }
};


class Solution {
 public:
  TreeNode* mirrorTree(TreeNode* root) {
    stack<TreeNode*> stacktmp;
    if (!root)
      return nullptr;
    stacktmp.push(root);
    while (!stacktmp.empty()) {
      TreeNode* node = stacktmp.top();
      stacktmp.pop();
      if (node->left)
        stacktmp.push(node->left);
      if (node->right)
        stacktmp.push(node->right);
      TreeNode* tmp = node->left;
      node->left = node->right;
      node->right = tmp;
    }
    return root;
  }
};
int main() {
  return 0;
}