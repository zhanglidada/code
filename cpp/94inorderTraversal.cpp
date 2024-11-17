#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>
#include <string>

typedef struct TreeNode TreeNode_t;
struct TreeNode {
  int         val;
  TreeNode*   left;
  TreeNode*   right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 使用递归的方法
class Solution {
  public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;

    inorder(root, res);

    return res;
  }

  void inorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
      return;

    inorder(root->left, res);
    res.emplace_back(root->val);
    inorder(root->right, res);
  }
};

// 使用循环迭代的方法，借用栈来保存访问路径上的根节点
// 其实迭代方法和递归方法本质上是一样的，不过迭代方法利用的是函数栈来保存路径上的节点
class Solution {
  public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;  // 保存访问路径上的节点

    if (root == nullptr)
      return res;

    while (root != nullptr || !stk.empty()) {
      // 一直向左走到底，保存路径上的节点
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();
      res.emplace_back(root->val);

      root = root->right;
    }
    return res;
  }
};