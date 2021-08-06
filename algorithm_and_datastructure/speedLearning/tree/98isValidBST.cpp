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

// 二叉搜索树的中序遍历严格递增
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (root == nullptr)  return true;
    midOrder(root);
    for (int i = 1; i < orderQueue.size(); i++) {
      if (orderQueue[i] <= orderQueue[i - 1])
        return false;
    }
    return true;
  }
  void midOrder(TreeNode* root) {
    if (root == nullptr)  return;
    midOrder(root->left);
    orderQueue.push_back(root->val);
    midOrder(root->right);
  }
 private:
  vector<int> orderQueue;
};

// 用一个栈进行中序遍历
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (root == nullptr)  return true;

    while (!stackNode.empty() || root != nullptr) {
      while (root != nullptr) {
        stackNode.push(root);
        root = root->left;
      }

      TreeNode* tmpNode = stackNode.top();
      stackNode.pop();
      // 按照中序遍历出栈的顺序判断是否有序
      if (tmpNode->val <= inOrder)  return false;
      inOrder = tmpNode->val;

      // 无论出栈节点右子树是否为空，root都要指向其右节点
      root = tmpNode->right;
    }
    return true;
  }
 private:
  stack<TreeNode*> stackNode;
  long long inOrder = (long long)INT_MIN - 1;
};

// 分治法，对每个节点，左子树的最大值小于根小于右子树的最小值
class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    if (root == nullptr)  return true;
    return helper(root, LONG_LONG_MIN, LONG_LONG_MAX);
  }
  bool helper(TreeNode* root, long long lower, long long upper) {
    if (root == nullptr)  return true;
    if (root->val <= lower || root->val >= upper)  return false;
    // 分治，分别判断左右子树是否满足条件
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
  }
};