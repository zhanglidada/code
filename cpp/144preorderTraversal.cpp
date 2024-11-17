#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <string>

struct TreeNode {
  int         val;
  TreeNode*   left;
  TreeNode*   right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 使用递归实现前序遍历
class Solution {
  public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;

    if (root == nullptr)
      return res;

    preorder(root, res);

    return res;   
  }

  void preorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
      return;
    
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
  }
};

// 使用迭代实现前序遍历
class Solution {
  public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;

    if (root == nullptr)
      return res;

    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        // 从根节点开始逐步压栈当前节点，以及当前节点的左子树的根节点
        // 压栈节点的同时将根节点的值放入res中
        res.push_back(root->val);
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();
      root = root->right;
    }

    return res;
  }
};