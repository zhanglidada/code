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

// 采用递归的方式来实现
class Solution {
  public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;

    if (root == nullptr)
      return res;

    postorder(root, res);

    return res;
  }

  void postorder(TreeNode* root, vector<int>& res) {
    if (root == nullptr)
      return;

    postorder(root->left, res);
    postorder(root->right, res);
    res.emplace_back(root->val);
  }
};


// 使用循环迭代的方式
// 不同于前序和中序遍历，此时需要一个prev指针
class Solution {
  public:
  vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> stk;
    vector<int> res;
    TreeNode* prev = nullptr;

    while (root != nullptr || !stk.empty()) {
      // 一直压栈左子树的根节点，直到为空
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }

      root = stk.top();
      stk.pop();

      // 当前节点右子树为空，或者右子树访问过
      if (root->right == nullptr || root->right == prev) {
        res.emplace_back(root->val);
        prev = root;  // prev指向当前节点
        root = nullptr;
      }
      else {
        // 右子树不为空，压栈当前节点并继续访问右子树
        stk.push(root);
        root = root->right;
      }
    }
    return res;
  }
};